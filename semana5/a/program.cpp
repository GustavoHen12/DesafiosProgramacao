#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<ll> plis;
vector<ll> chegou_na_hora;
ll n, h;

ll pedidos(int num, int ini, int fim)
{
    ll quant = 0;
    for (int i = ini; i < fim; i++)
    {
        if (plis[i] > num)
            quant++;
    }

    return quant;
}

ll swaps = 0;
void merge_sort(int l, int r) {
    if (r - l == 1)
    {
        return;
    }
    int mi = l + (r - l) / 2;
    merge_sort(l, mi);
    merge_sort(mi, r);
    vector<ll> aux(r - l);
    int i = l, j = mi;
    for (int k = 0; k < r - l; k++) {
        if (i < mi && j < r) {
            if (!(plis[i] < plis[j]) && !binary_search(chegou_na_hora.begin(), chegou_na_hora.end(), plis[j])) {
                swaps += mi - i;
            }
            if (plis[i] < plis[j]) {
                aux[k] = plis[i++];
            }
            else {
                aux[k] = plis[j++];
            }
        }
        else if (i < mi) {
            aux[k] = plis[i++];
        }
        else{
            aux[k] = plis[j++];
        }
    }
    copy(aux.begin(), aux.end(), plis.begin() + l);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    cin >> n >> h;
    for(int i = 1; i <= n; i++){
        ll part;
        cin >> part;
        plis.push_back(part);
        if(i <= h){
            chegou_na_hora.push_back(part);
        }
    }
    
    sort(chegou_na_hora.begin(), chegou_na_hora.end());
    swaps = 0;
    merge_sort(0, n);

    cout << swaps << "\n";
}