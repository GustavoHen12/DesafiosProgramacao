#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void encontraSubconj(vector<ll>& A, vector<vector<ll> >& res, vector<ll>& subset, int index) {
    res.push_back(subset);
    for (int i = index; i < A.size(); i++) {  
        subset.push_back(A[i]);  
        encontraSubconj(A, res, subset, i + 1);  
        subset.pop_back();
    }
    return;
}
  
ll quantindadeMultiplos(ll n, ll a, ll b) {
    if(n > b || n <= 0) return 0;
    ll result = 0;
    if(a >= n){
        ll quanA = ceil(a/(n +0.0));
        ll quanB = floor(b/(n + 0.0));
        result = quanB - quanA + 1;
    } else {
        result = floor(b/(n +0.0));
    }
    return result > 0 ? result : 0;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll a, b, n;
    cin >> a >> b >> n;
    vector<ll> primos (n);for (ll& x : primos) { cin >> x; }    
    ll quantTotal = 0, quantIntersec = 0;

    sort(primos.begin(), primos.end());

    vector<ll> subset;
    vector<vector<ll> > res;
    encontraSubconj(primos, res, subset, 0);

    for (int i = 0; i < res.size(); i++) {
        if(res[i].size() > 0){
            int sinal = res[i].size() == 1 ? 1 : (res[i].size() % 2 == 0 ? 1 : -1);
            ll mult = 1;
            for (int j = 0; j < res[i].size(); j++) {
                mult *= res[i][j];
                //cout << res[i][j] << " ";
            }
            quantIntersec += (sinal * quantindadeMultiplos(mult, a, b));
            //cout << " = " << sinal << "*" << mult << " (" << quantIntersec << ")"<< "\n";
        }
    }

    cout << (b - a + 1) - (quantIntersec) << "\n";
}