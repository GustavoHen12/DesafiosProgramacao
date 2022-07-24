#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define MAX 12345
const ll oo = 1987654321987654321;

ll graf[MAX][MAX];
ll lot[MAX];

struct edge {
    int u, v, w;
};
vector<ll> d(MAX, oo);
vector<edge> edges;

void bellman_ford(int src, int n)
{
    d[src] = 0;
    for (int i = 0; i < n - 1; i++)
        for (auto e : edges)
            if (d[e.u] != oo && d[e.v] > d[e.u] + e.w)
                d[e.v] = d[e.u] + e.w;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    int n, m;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> lot[i];
    }

    cin >> m;

    // vector<vector<ll>> d(n, vector<ll>(n, oo));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edge e;
        e.u = a;
        e.v = b;
        e.w = lot[b] - lot[a];
        edges.push_back(e);
        // d[--a][--b] = lot[b] - lot[a];
    }

    int q;
    cin >> q;
    bellman_ford(1, n);
    while (q--) {
        int consulta;
        cin >> consulta;
        ll lucro = d[consulta];
        // ll lucro = d[0][--consulta];
        if (lucro < 3 || lucro == oo)
            cout << "Não, Edsger...\n";
        else
            cout << lucro << "\n";
    }
}