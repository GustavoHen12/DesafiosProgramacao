#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n, falta;
    ll razaoErrada = -1, razaoCorreta = 0;
    cin >> n;
    
    tuple<ll, int, ll> razao_A(-1, 0, 0);
    tuple<ll, int, ll> razao_B(-1, 0, 0);
    vector<ll> pg (n);for (ll& x : pg) { cin >> x; }
    sort(pg.begin(), pg.end());

    for (int i = 0; i < n; i++) {
        ll num = pg[i];
        if(i > 0){
            ll razao = num / pg[i-1];
            if(razao == get<0>(razao_A) || get<1>(razao_A) == 0){
                get<0>(razao_A) = razao;
                get<1>(razao_A)++;
                get<2>(razao_A) = pg[i-1];
            } else if (razao == get<0>(razao_B) || get<1>(razao_B) == 0){
                get<0>(razao_B) = razao;
                get<1>(razao_B)++;
                get<2>(razao_B) = pg[i-1];
            }
        }
    }

    if(get<1>(razao_A) == 1){
        falta = get<2>(razao_A);
        razaoCorreta = get<0>(razao_B);
    } else if (get<1>(razao_B) == 1) {
        falta = get<2>(razao_B);
        razaoCorreta = get<0>(razao_A);
    } else {
        razaoCorreta = get<0>(razao_A) == -1 ? get<0>(razao_B) : get<0>(razao_A);
    }

    if(get<1>(razao_B) == 0 || get<1>(razao_A) == 0){
        if((pg[0] / razaoCorreta > 0) && razaoCorreta != 1)
            cout <<  pg[0] / razaoCorreta << "   \n";
        cout << pg[n-1] * razaoCorreta << "  \n";
    } else {
        cout << falta * razaoCorreta << "    \n";
    }
}