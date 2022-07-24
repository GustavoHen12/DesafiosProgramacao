#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;

    vector<ll> vet (n); for (ll& x : vet) { cin >> x; }
    
    //vector<ll> pos(n, 0), neg(n, 0);
    map<ll, int> m;
    ll max = 0, retira, adiciona;
    int index_sv = 0;
    for(int i = 0; i < n; i++){
        adiciona = vet[i];
        if(i >= k) {
            retira = vet[i - k];
            ll v_retira = m[retira];
            if(v_retira <= 1){
                m.erase(retira);
            } else {
                m[retira] = v_retira - 1;
            }
        }

        ll v_adiciona = 0;
        if(m.count(adiciona) > 0){
            v_adiciona = m[adiciona];
        }

        v_adiciona++;
        m[adiciona] = v_adiciona;
        if(v_adiciona > max)
            max = v_adiciona;
    }

    cout << max << "\n";
}