#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    ll a, b, c;
    cin >> a >> b >> c;
    ll delta = (b*b) - (4 * a *c);

    ll raiz = 0;
    ll i = 0;
    while(raiz < delta){
        raiz = i*i;
        i++;
    }

    if(raiz == delta)
        cout << "Y\n";
    else
        cout << "N\n";
}