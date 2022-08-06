#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
const int M = 1e9;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    ll n, h, v;

    cin >> n >> h >> v;

    ll num_a = v/n;
    ll res =(num_a + h -1) / h;

    cout << res << "\n";
}