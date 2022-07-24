#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll competidores, vagas;
    cin >> competidores >> vagas;
    
    for(int i = 2; i <= competidores; i+=2){
        if(vagas > 0){
            cout << i << "\n";
            vagas--;
        }
    }
    if(vagas > 0){
        for(int i = 1; i <= competidores; i+=2){
            if(vagas > 0){
                cout << i << "\n";
                vagas--;
            }
        }
    }
}