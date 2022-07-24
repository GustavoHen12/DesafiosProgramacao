#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll lucro = 0;
int p, h, f;
int lucro_h, lucro_f;

ll calculoLucro () {
    if(p < 2)
        return 0;
    if(h > 0 && (lucro_h >= lucro_f || f <= 0)){
        h--; p-= 2;
        return calculoLucro() + lucro_h;
    } else if(f > 0) {
        f--; p-= 2;
        return calculoLucro() + lucro_f;
    }

    return 0;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int iter; cin >> iter;

    while(iter--){
        cin >> p >> h >> f >> lucro_h >> lucro_f;
        lucro = 0;
        lucro = calculoLucro();
        cout << lucro << "\n";
    }
}