#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int L = log2(1123456789)+1;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    ll n, q;
    cin >> n >> q;

    vector<vector<int>>planetas(L+1, vector<int>(n+1));
    
    // Monta
    for (ll u = 1; u <= n; u++) {
        ll v;
        cin >> v;
        // v--;
        planetas[0][u] = v;
    }

    // Preenche
    for(ll i = 1; i <= L; i++){
        for(ll j = 1; j<= n; j++){
            planetas[i][j] = planetas[i-1][(planetas[i-1][j])];
        }
    }

    // for(ll i = 1; i <= n; i++){
    //     cout << i << " > ";
    //     for(ll j = 1; j <= n; j++){
    //         cout << planetas[i][j] << " |";
    //     }
    //     cout << endl;
    // }

    // Faz as consultas
    for(int i = 0; i < q; i++){
        int ori, dist;
        cin >> ori >> dist;

        int planeta = ori;
        for(int i = L; i >= 0; i--) {
            if(dist & (1 << i)){
                planeta = planetas[i][planeta];
            }
        }
        cout << planeta << "\n";
    }
}