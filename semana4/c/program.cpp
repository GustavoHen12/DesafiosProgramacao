#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    int areas; cin >> areas;
    ll roubou = 0;
    for(int i = 0; i < areas; i++){
        int quant; cin >> quant;
        if(quant > 10){
            roubou += quant - 10;
        }
    }
    
    cout << roubou << "\n";
}