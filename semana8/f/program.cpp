#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    ll iter; cin >> iter;
    while(iter--){
        ll n, d;
        cin >> n >> d;
        // vector<int> a;
        cout << "[";
        int quant = 0;
        while(d) {
            if(quant == 1)
                cout << ";";
            else if(quant > 1)
                cout << ",";
            quant++;
            cout << n / d;
            tie(n, d) = make_pair(d, n % d);
        }
        cout << "]";
        cout << "\n";
    }
}