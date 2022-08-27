#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using ii = pair<int, int>;

const int N = 50000, B = ceil(sqrt(N));

vector<vector<ii>> g(N);

#define NEUTRAL 0
#define OP(X, Y) (X + Y)

vector<int> depth(N);
vector<int> up(N);
vector<int> weiop(N);
vector<int> bup(N);
vector<int> bweiop(N);

int std_lca(int a, int b) {
    if (!(depth[a] / B > depth[b] / B)) {
        swap(a, b);
    }
    while (depth[a] / B > depth[b] / B) {
        a = bup[a];
    }
    if (!(depth[a] > depth[b])){
        swap(a, b);
    }
    while (depth[a] > depth[b]) {
        a = up[a];
    }
    while (a != b) {
        a = up[a];
        b = up[b];
    }
    return a;
}

int stdt_op(int a, int b)
{
    int ans = NEUTRAL;
    if (!(depth[a] / B > depth[b] / B))
    {
        swap(a, b);
    }
    while (depth[a] / B > depth[b] / B)
    {
        ans = OP(ans, bweiop[a]);
        a = bup[a];
    }
    if (!(depth[a] > depth[b]))
    {
        swap(a, b);
    }
    while (depth[a] > depth[b])
    {
        ans = OP(ans, weiop[a]);
        a = up[a];
    }
    while (a != b)
    {
        ans = OP(ans, OP(weiop[a], weiop[b]));
        a = up[a];
        b = up[b];
    }
    return ans;
}

void stdt_decompose(int u, int p, int w) {
    up[u] = p;
    weiop[u] = w;
    depth[u] = depth[p] + 1;
    bup[u] = depth[u] % B ? bup[p] : p;
    bweiop[u] = OP(depth[u] % B ? bweiop[p] : NEUTRAL, w);
    for (auto [v, w] : g[u])
        if (v != p)
            stdt_decompose(v, u, w);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    int n, m, q;
    cin >> n;

    vector<pair<int, int>> cartas(n, make_pair(-1, -1));
    for(int i = 0; i < n; i++){
        int ct; cin >> ct;
        ct--;

        if(cartas[ct].first == -1){
            cartas[ct].first = i;
        } else {
            cartas[ct].second = i;
        }
    }

    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        u--;
        v--;
        g[u].push_back(ii(v, 1));
        g[v].push_back(ii(u, 1));
    }

    stdt_decompose(0, 0, 0);
    int total = 0;
    int pairs = n/2;
    int i = 0;
    while (i < pairs){
        total += depth[cartas[i].first] + depth[cartas[i].second] - 2*depth[std_lca(cartas[i].first, cartas[i].second)];
        i++;
    }
    cout << total << "\n";
}