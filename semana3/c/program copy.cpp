#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll a, b, n;
    cin >> a >> b >> n;
    ll size = b - a + 1;
    vector<ll> primos;
    vector<bool> crivo(size, true);
    cout << crivo.max_size() << endl;

    ll quantRetirados = 0;
    for(ll i = 0; i < n; i++){
        ll primo;
        cin >> primo;
        if(primo > 0){
            ll start = primo > a ? primo : (ceil(a/primo) * primo);
            ll j = start;
            while(j <= b){
                if(j >= a && j <= b && crivo[j - a]){
                    crivo[j - a] = false;
                    quantRetirados ++;
                }
                j+= primo;
            }
        }
    }

    cout << size - quantRetirados << "\n";
}
