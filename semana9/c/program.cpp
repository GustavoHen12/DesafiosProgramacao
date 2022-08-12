#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n;
const int N = 1e5+15;
vector<int> tin(N), low(N);
vector<bool> visited(N);

ll tk, bridges;

void dfs(vector<vector<int>> &graph, int u, int p){
    visited[u] = true;
    tin[u] = low[u] = tk++;
    for(auto v : graph[u]){
        if (v == p)
            continue;
        else if (tin[v] == -1) {
            dfs(graph, v, u);
            if (low[v] > tin[u])
                bridges++;
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], tin[v]);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    int iter; cin >> iter;
    for(int c = 0; c < iter; c++){
        ll nodos, arestas;
        cin >> nodos >> arestas;
        n = nodos;
        
        tin.assign(n, -1);
        low.assign(n, -1);
        visited.assign(n, false);

        tk = 0;
        bridges = 0;
        
        vector<vector<int>> graph(N);

        int u, v;
        for(ll i = 0; i < arestas; i++){
            cin >> u >> v;
            u--;
            v--;
            (graph[u]).push_back(v);    
            (graph[v]).push_back(u);    
        }

        for(ll i = 0; i < n; i++){
            if(!visited[i]){
                dfs(graph, i, i);
            }
        }

        cout << bridges << endl;
    }
}