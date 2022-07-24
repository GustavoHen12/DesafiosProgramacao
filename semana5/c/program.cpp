#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    int n; cin >> n;
    vector<int> index(n+1);
    vector<int> pilhas(n+1, 0);

    for(int i = 1; i <= n; i++){
        cin >> pilhas[i];
        index[i] = pilhas[i] + index[i - 1];
    }

    // for(int i = 0; i <= n; i++){
    //     cout << index[i] << " ";
    // }
    // cout << "\n";

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int busca;
        cin >> busca;
        auto it = upper_bound(index.begin(), index.end(), busca);
        auto it_ant = it;
        it_ant--;
        if(it == index.end()) --it;
        // cout << *(it_ant) << " -- ";
        int num = *(it_ant) == busca ? it_ant - index.begin() : it - index.begin(); 
        // cout << "(" << busca <<") " << num << "\n";
        cout << num << "\n";
    }    
}