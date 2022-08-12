#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n;
const int N = 1e5+15;

vector<int> tin(N), low(N);
vector<bool> visited(N);

ll tk, bridges;

void dfs(vector<vector<int>> &graph, int u, int p = -1){
    visited[u] = true;
    tin[u] = low[u] = tk++;
    for(auto v : graph[u]){
        if(v == p) continue;
        if(visited[v]){
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(graph, v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u]){
                bridges++;
            }
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
        
        vector<vector<int>> graph;
        for(int i = 0; i < nodos; i++){
            vector<int> adj;
            graph.push_back(adj);
        }

        int u, v;
        for(ll i = 0; i < arestas; i++){
            cin >> u >> v;
            (graph[u]).push_back(v);    
            (graph[v]).push_back(u);    
        }

        for(ll i = 0; i < n; i++){
            if(!visited[i]){
                dfs(graph, i);
            }
        }

        cout << bridges << endl;
    }
}