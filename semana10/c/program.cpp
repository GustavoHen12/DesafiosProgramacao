#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using ii = pair<ll, ll>;
const ll N = 1e5+15;
vector<vector<ii>> g (N);
#define NEUTRAL 0
#define OP(X, Y) (X + Y)

const ll L = log2(N);
vector<ll> depth(N, 0);
vector<vector<ll>> weiop(N, vector<ll>(L + 1));
vector<vector<ll>> up(N, vector<ll>(L + 1));

void bl_euler_tour(ll u, ll p, ll w){
    up[u][0] = p;
    weiop[u][0] = w;
    depth[u] = depth[p] + 1;
    for (auto [v, w] : g[u])
        if (v != p)
            bl_euler_tour(v, u, w);
}

void bl_init(ll u, ll n) {
    depth[u] = 0;
    bl_euler_tour(u, u, 0);
    for (ll l = 0; l < L; l++)
        for (ll u = 0; u < n; u++)
        {
            ll a = up[u][l];
            up[u][l + 1] = up[a][l];
            weiop[u][l + 1] = OP(weiop[u][l], weiop[a][l]);
        }
}

ll bl_op(ll a, ll b) {
    if (!(depth[a] > depth[b]))
    {
        swap(a, b);
    }
    ll res = NEUTRAL;
    ll diff = depth[a] - depth[b];
    for (ll l = L; l >= 0; l--)
        if (diff & (1 << l))
        {
            res = OP(res, weiop[a][l]);
            a = up[a][l];
        }
    if (a == b)
    {
        return res;
    }
    for (ll l = L; l >= 0; l--)
        if (up[a][l] != up[b][l])
        {
            res = OP(res, OP(weiop[a][l], weiop[b][l]));
            a = up[a][l], b = up[b][l];
        }
    return OP(res, OP(weiop[a][0], weiop[b][0]));
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n;
    
    for(ll i = 1; i < n; i++){
        ll d, c;
        cin >> d >> c;
        g[i].push_back(ii(d, c));
        g[d].push_back(ii(i, c));
    }

    bl_init(0, n);
    ll q;
    cin >> q;
    for(ll j = 0; j < q; j++){
        ll src, dest;
        cin >> src >> dest;
        ll menor_dist = bl_op(src, dest);
        cout << menor_dist << "\n";
    }

}