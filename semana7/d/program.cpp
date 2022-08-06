#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    ll interac;
    cin >> interac;

    while(interac--){
        ll n;
        cin >> n;

        ll fact = 1;
        ll digs = 1;
        for(ll i = 2; i <= n; i++){
            fact = fact*i;
            while(fact %10 == 0){
                fact = fact / 10;
                digs++;
            }
        }
        
        while(fact >= 10){
            fact = fact / 10;
            digs++;
        }

        cout << fact << " " << digs << "\n";
    }
}