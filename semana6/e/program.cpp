#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll oo = 1987654321987654321;
int n, m;

using edge = pair<int, int>;
vector<vector<edge>> edges(200);

ll maior_distancia(int src){
    vector<ll> d (n, oo);
    vector<bool> visitou(n, false);

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
            //cout << "(" << v << "  " << w << ")\n";
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                queue.push({d[v], v});
            }
        }
    }

    ll maior = 0;
    //cout << "src: " << src << "\n";
    for(int i = 0; i < n; i++) {
        //cout << d[i] << "\n";
        if(d[i] != oo && d[i] > maior)
            maior = d[i];
    }
    
    return maior;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    cin >> n >> m;
    ll menor = oo;

    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    for(int i = 0; i < n; i++) {
        ll maior = maior_distancia(i);
        if(maior < menor)
            menor = maior;
    }

    //cout << "--\n";
    cout << menor << "\n";
}