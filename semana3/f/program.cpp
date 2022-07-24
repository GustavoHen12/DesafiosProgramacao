#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n, falta, razaoErrada = 0, razaoCorreta = 0;
    cin >> n;
    map<ll, int> m;
    map<ll, ll> ultimoNum;
    vector<ll> pg (n);for (ll& x : pg) { cin >> x; }
    sort(pg.begin(), pg.end());

    for (int i = 0; i < n; i++) {
        ll num = pg[i];
        if(i > 0){
            ll razao = num / pg[i-1];
            int quant = 0;
            if(m.count(razao) > 0){
                quant = m[razao];
                razaoCorreta = razao;
            }
            quant++;
            m[razao] = quant;
            ultimoNum[razao] = pg[i-1];
        }
    }

    for (auto const& x : m){
        if(x.second == 1){
           razaoErrada = x.first;
           falta = ultimoNum[razaoErrada];
        } else {
            razaoCorreta = x.first;
        }
    }

    if(m.size() == 1){
        ll ant = pg[0] / razaoCorreta; 
        if(pg[0]%razaoCorreta == 0 && ant != pg[0] && ant > 0){
            cout << ant << "\n";
        }
        cout << pg[n-1] * razaoCorreta << "\n";
    } else {
        cout << falta * razaoCorreta << "\n";
    }
}