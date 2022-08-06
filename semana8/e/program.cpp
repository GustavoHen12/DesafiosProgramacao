#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica
    ll iter; cin >> iter;
    while(iter--){
        ll a_1, a_2, b_1, b_2;
        cin >> a_1 >> a_2 >> b_1 >> b_2;
        cout << gcd((a_1 - b_1), (a_2 - b_2)) + 1 << "\n";
    }
}