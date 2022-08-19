#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    ll n, q;
    cin >> n >> q;

    vector<ll> p(n+1);
    vector<ll> becoSemSaida(n+1, false);
    for(ll i = 1; i <= n; i++){
        ll dest;
        cin >> dest;
        p[i] = dest;
        becoSemSaida[i] = i == dest;
    }

    vector<ll> consultas(q, 0);
    for(ll i = 0; i < q; i++){
        ll planeta, count;
        cin >> planeta >> count;
        ll start = planeta;
        for(ll j = 1; j <= count; j++){
            planeta = p[planeta];
            if(becoSemSaida[planeta])
                break;
            
            if(planeta == start){
                ll n_count = count - ((count/j) * j);
                for(ll k = 0; k < n_count; k++){
                    planeta = p[planeta];
                    if(becoSemSaida[planeta])
                        break;
                }
                break;
            }
        }
        cout << planeta << "\n";
    }

}