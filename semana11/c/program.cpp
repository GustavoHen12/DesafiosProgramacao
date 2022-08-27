#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1000000;
#define NEUTRAL 0
#define FACTOR sz
#define OP(X, Y) (X + Y)

vector<ll> t(4 * N);
vector<ll> lazy(4 * N, 0);
vector<ll> markTo(4 * N);
vector<bool> mark (4 * N);
int range;

void auxPush(int v, int ch){
    if(mark[v]){
        mark[ch] = true;
        markTo[ch] = markTo[v];
        lazy[ch] = lazy[v];
    }else {
        lazy[ch] += lazy[v];
    }
}

void push(int v, int tl, int tr) {
    if (mark[v]) {
        t[v] = (tr - tl + 1) * markTo[v];
    }

    if(v < 0 || v > t.size()){
        cout << t.size() << endl;
        cout << "erro: " << v << endl;
    }

    t[v] += (tr - tl + 1) * lazy[v];

    if(tl != tr){
        auxPush(v, 2*v);
        auxPush(v, 2*v + 1);
    }

    lazy[v] = 0;
    mark[v] = false;
}

void update_set(int v, int tl, int tr, int l, int r, int new_val) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        mark[v] = true;
        markTo[v] = new_val;
        lazy[v] = 0;
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update_set(v*2, tl, tm, l, min(r, tm), new_val);
        update_set(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
        push(v*2, tl, tm);
        push(v*2+1, tm+1, tr);
        // cout << "t[" << v << "] = t[" << (v * 2) << "] + t[" << v * 2 + 1 << "]" << "\n";
        // cout << "[" << t[v] << "] = [" << t[(v * 2)] << "] + [" << t[v * 2 + 1] << "]" << "\n\n";

        t[v] = OP(t[v * 2], t[v * 2 + 1]);
    }
}

void update_add(int v, int tl, int tr, int l, int r, int addend){
    if (l > r) {
        return;
    }
      
    if (l == tl && tr == r) {
        // t[v] += addend;
        lazy[v] += addend;
        return;
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update_add(v*2, tl, tm, l, min(r, tm), addend);
        update_add(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        push(v*2, tl, tm);
        push(v*2+1, tm+1, tr);
        // cout << "t[" << v << "] = t[" << (v * 2) << "] + t[" << v * 2 + 1 << "]" << "\n";
        // cout << "[" << t[v] << "] = [" << t[(v * 2)] << "] + [" << t[v * 2 + 1] << "]" << "\n\n";
        t[v] = OP(t[v * 2], t[v * 2 + 1]);
    }
}

ll get_sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;

    push(v, tl, tr);

    if (l <= tl && tr <= r){
        return t[v];
    }
    
    int tm = (tl + tr) / 2;
    return (get_sum(v*2, tl, tm, l, min(r, tm)) + get_sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void build(vector<int> &src, int ti = 1, int tl = 1, int tr = N) {
    if (tl == tr)
    {
        if (tl < src.size())
        {
            t[ti] = src[tl];
        }
        return;
    }
    int tm = (tl + tr) / 2;
    build(src, ti * 2, tl, tm);
    build(src, ti * 2 + 1, tm + 1, tr);
    t[ti] = OP(t[ti * 2], t[ti * 2 + 1]);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    vector<int> src(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> src[i];
    }

    build(src);
    
    for(int i = 0; i < q; i++){
        int op, auxA, auxB;
        cin >> op >> auxA >> auxB;
        if(op == 1){
            int k;
            cin >> k;
            update_add(1, 1, N, auxA, auxB, k);
        } else if (op == 2){
            int k;
            cin >> k;
            update_set(1, 1, N, auxA, auxB, k);
        } else {
            cout << get_sum(1, 1, N, auxA, auxB) << endl;
        }
    }
}