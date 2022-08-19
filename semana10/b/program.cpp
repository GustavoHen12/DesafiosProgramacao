#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int oo = 987654321;
const int N = 1e4 + 15;
vector<vector<int>> res(N);

struct edge { int u, v, cap; };

vector<edge> edges;

#define pb push_back

vector<int> queu(N), ix(N), dist(N), par(N);
bool minimum_path(int s, int t)
{
    fill(dist.begin(), dist.end(), oo);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        queu[u] = 0;
        for (int i : res[u])
        {
            edge e = edges[i];
            int v = e.v;
            if (e.cap && dist[v] > dist[u] + e.cap)
            {
                dist[v] = dist[u] + e.cap;
                par[v] = u;
                ix[v] = i;
                if (!queu[v])
                {
                    q.push(v);
                    queu[v] = 1;
                }
            }
        }
    }
    return dist[t] < oo;
}

pair<int, int> ffek(int s, int t)
{
    int min_cost = 0, max_flow = 0;
    while (minimum_path(s, t))
    {
        int flow = oo;
        for (int u = t; u != s; u = par[u])
        {
            flow = min(flow, edges[ix[u]].cap);
        }
        for (int u = t; u != s; u = par[u])
        {
            edges[ix[u]].cap -= flow;
            edges[ix[u]^1].cap += flow;
        }
        min_cost += flow * dist[t];
        max_flow += flow;
    }

    return {min_cost, max_flow};
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        res[u].pb(edges.size());
        edges.pb({u, v, 1});
        res[v].pb(edges.size());
        edges.pb({v, u, 1});
    }

    auto [min_cost, max_flow] = ffek(0, n - 1);
    cout << max_flow << "\n";
}