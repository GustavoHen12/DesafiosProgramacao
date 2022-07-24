#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll oo = 1987654321987654321;
int n, m, c, k;

using edge = pair<int, int>;
vector<vector<edge>> edges(300);
vector<int> pai(300, -1);

ll menor_distancia(int src, int des, bool considerar_rota){
    vector<bool> visitou(n, false);
    vector<ll> d (n, oo);

    if(considerar_rota){
        for(int i = 0; i < des; i++)
            visitou[i] = true;
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> queue;
    d[src] = 0;
    queue.push({0, src});
    while(!queue.empty()){
        auto[c, u] = queue.top();
        queue.pop();

        if(visitou[u]){
            continue;
        }

        visitou[u] = true;
        for(auto [v, w] : edges[u]){
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                pai[v] = u;
                queue.push({d[v], v});
            }
        }
    }

    return d[des];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    cin >> n >> m >> c >> k;
    
    int bkp[n][n];
    memset(bkp, n*n, 0);

    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        if(u < c){
            if(v < c){
                if(abs(u-v) > 1){
                    continue;
                } else if (u < v) {
                    edges[u].push_back({v, w});
                } else {
                    edges[v].push_back({u, w});
                    continue;
                }
            }
            edges[v].push_back({u, w});
        } else {
            if(v < c){
                edges[u].push_back({v, w});
            } else {
                edges[u].push_back({v, w});
                edges[v].push_back({u, w});
            }
        }
        bkp[u][v] = w;
        bkp[v][u] = w;
    }

    ll menor_dist = menor_distancia(k, c-1, false);

    cout << menor_dist << "\n";
    // ll menor_dist_sem_rota = menor_distancia(k, c-1, true);
    // ll menor_dist = menor_distancia(k, c-1, false);

    // int caminho = c-1;
    // ll menor_caminho_dina = 0;
    // ll primeiro_rota = -1, preco_fora_rota = 0;
    // do {
    //     menor_caminho_dina += bkp[pai[caminho]][caminho];
    //     caminho = pai[caminho];
    //     if(caminho < (c-1)){
    //         primeiro_rota = caminho;
    //         preco_fora_rota = menor_caminho_dina;
    //     }
    // } while(caminho != k);
    
    // if(primeiro_rota != -1){
    //     ll acu = 0;
    //     for(int i = primeiro_rota; i < (c-1); i++){
    //         acu += bkp[i][i+1];
    //     }
    //     menor_caminho_dina = menor_caminho_dina - preco_fora_rota + acu;
    // }

    // cout << min(menor_caminho_dina, menor_dist_sem_rota) << "\n";
}