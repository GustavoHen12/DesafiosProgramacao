#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 15;
#define NEUTRAL 0
#define OP(X, Y) ((X) + (Y))
vector<ll> t(2 * N);

ll op_inclusive(ll l, ll r) {
    r++;
    ll left = NEUTRAL, right = NEUTRAL;
    for (l += N, r += N; l < r; l /= 2, r /= 2)
    {
        if (l & 1)
            left = OP(left, t[l++]);
        if (r & 1)
            right = OP(right, t[--r]);
    }
    return OP(left, right);
}

void set_value(ll i, ll v) {
    t[i += N] = v;
    for (i /= 2; i > 0; i /= 2)
        t[i] = OP(t[i * 2], t[i * 2 + 1]);
}

void build(vector<int> &src) {
    for (int i = 1; i < src.size(); i++)
        t[N + i] = src[i];
    for (int i = N - 1; i > 0; i--)
        t[i] = OP(t[2 * i], t[2 * i + 1]);
}

ll consultarDr (ll ini, ll fim) {
    ll sum = op_inclusive(ini, fim);
    return sum % 9;
}

ll calculaDr (ll num) {
    ll sum = 0;
    while (num != 0) {
        sum += num % 10;
        num = num / 10;
    }

    return sum % 9;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    ll n, q;
    cin >> n;

    string num_str;
    cin >> num_str;
    vector<int> tb(n+1);
    for(int i = 1; i <= num_str.length(); i++){
        tb[i] = (num_str[i-1]-'0');
    }

    build(tb);

    cin>>q;
    while(q--){
        int op;
        cin >> op;
        if(op < 3) {
            int a1, a2, b1, b2, d;
            cin >> a1 >> a2 >> b1 >> b2 >> d;
            ll drA = consultarDr(a1, a2); 
            ll drB = consultarDr(b1, b2);

            ll dig = 0;
            if(op == 1) {
                dig = calculaDr(drA + drB);
            } else {
                dig = calculaDr(drA * drB);
            }

            if(dig == d) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            int pos, num;
            cin >> pos >> num;

            tb[pos] = num;
            set_value(pos, num);
        }
    }
}