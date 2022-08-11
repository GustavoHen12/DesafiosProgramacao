#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n, m;
const int N = 1e5+15;
vector<vector<int>> graph(N);
vector<bool> visited(N);
vector<int> childNodes(N, 0);
vector<int> lastSource(N, -1);

ll tk, bridges;

void dfs(int u, int p, int source){
    visited[u] = true;
    for(auto v : graph[u]){
        if(v == p) continue;
        if(!visited[v]){
            if(lastSource[v] != source){
                childNodes[v]++;
            }
            lastSource[v] = source;
            dfs(v, u, source);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    cin >> n >> m;

    visited.assign(n, false);
    int u, v;
    vector<bool> sources(n+1, true);
    for(ll i = 0; i < m; i++){
        cin >> u >> v;
        u--;
        v--;
        (graph[u]).push_back(v);
        sources[v] = false;    
    }

    for(ll i = 0; i < n; i++){
        if(sources[i]){
            dfs(i, i, i);
            visited.assign(n, false);
        }
    }

    int max = 1;
    for(int i = 0; i < n; i++){
        if(childNodes[i] > max)
            max = childNodes[i];
    }
    
    if(max > 1)
        cout << max << "\n";
    else
        cout << "0\n";
}