#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> pre (string ne) {
    ll n = ne.size();
    vector<ll> pi(n, 0);
    for (ll i = 1, j = 0; i < n; i++) {
        while (j > 0 && ne[i] != ne[j]) {
            j = pi[j - 1];
        }
        if (ne[i] == ne[j]) {
            j++;
        }

        pi[i] = j;
    }
    return pi;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    string palavra;
    cin >> palavra;

    vector<ll> bordas = pre(palavra);

    // for (int x : pre(palavra)) { cout << x << " "; }
    // cout << "\n";

    vector<ll> resp;
    ll ind = palavra.length();
    while(ind > 0){
        ind = bordas[ind-1];
        resp.push_back(ind);
    }

    sort(resp.begin(), resp.end());
    for (int x : resp) {
        if(x > 0)
            cout << x << " ";
    }
    cout << "\n";
}