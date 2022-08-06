#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    ll n, m;
    cin >> n >> m;

    vector<ll> bar(n, 0);
    for(auto &x : bar) cin >> x;

    int maior = 0;
    int sum = 0, i = 0, j = 1;
    sum = bar[i];
    while(j < n){
        while(sum + bar[j] > m && i < j-1){
            sum -= bar[i];
            i++;
        }

        if(sum < m){
            sum += bar[j];
            j++;
        }

        if(sum <= m && sum > maior){
            maior = sum;
        }

        if(sum == m)
            break;
    }

    cout << maior << "\n";

}