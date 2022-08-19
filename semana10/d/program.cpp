#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll oo = 987654321;
const ll N = 1e4+15;
vector<vector<ll>> res (N);
struct edge { ll u, v, cap; };
vector<edge> edges;
#define pb push_back

vector<ll> ix(N), dist(N), par(N);
bool minimum_path(ll s, ll t)
{
    fill(dist.begin(), dist.end(), oo);
    dist[s] = 0;
    queue<ll> q;
    q.push(s);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        if (u == t)
        {
            break;
        }
        for (ll i : res[u])
        {
            edge e = edges[i];
            ll v = e.v;
            if (e.cap && dist[v] == oo)
            {
                dist[v] = dist[u] + 1;
                par[v] = u;
                ix[v] = i;
                q.push(v);
            }
        }
    }
    return dist[t] < oo;
}

pair<ll, ll> ffek(ll s, ll t)
{
    ll min_cost = 0, max_flow = 0;
    while (minimum_path(s, t))
    {
        ll flow = oo;
        for (ll u = t; u != s; u = par[u])
        {
            flow = min(flow, edges[ix[u]].cap);
        }
        for (ll u = t; u != s; u = par[u])
        {
            edges[ix[u]].cap -= flow;
            edges[ix[u]^1].cap += flow;
        }
        min_cost += flow * dist[t];
        max_flow += flow;
    }
    return {min_cost, max_flow};
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;

    for(ll i = 0; i < m; i++){
        ll u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        res[u].push_back(edges.size());
        edges.push_back({u, v, c});
        res[v].push_back(edges.size());
        edges.push_back({v, u, 0});
    }
    auto [min_cost, max_flow] = ffek(0, n-1);
    cout << max_flow << "\n";
}