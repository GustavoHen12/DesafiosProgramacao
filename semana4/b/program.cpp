#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<int> moedas {1, 5, 10, 25, 50};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int tr, maiorTroco = 0;
    vector<int> trocoList; 
    while(cin >> tr){
        trocoList.push_back(tr);
        if(tr > maiorTroco)
            maiorTroco = tr;
    }
    // sort(trocoList.begin(), trocoList.end());
    
    // calcula pro maior
    vector<ll> dp(maiorTroco + 1);
    dp[0] = 1;
    for(int i = 0; i < moedas.size(); ++i){
        for(int j = moedas[i]; j <= maiorTroco; ++j){
            dp[j] += dp[j - moedas[i]];
        }
    }

    for(auto& troc : trocoList){
        cout << dp[troc] << "\n";
    }
}

    // vector<vector<int>> dp;
    // for(int i = 0; i <= 3012345 + 1; i++){
    //     if(i == 0){
    //         vector<int> lin(6, 1); dp.push_back(lin);
    //     } else {
    //         vector<int> lin(6, 0); dp.push_back(lin);
    //     }
    // }
    
    // while(cin >> troco){
    //     for(int i = 1; i <= troco; i++){
    //         int com = 0;
    //         int sem = 0;
    //         for(int j = 0; j < moedas.size(); j++){
    //             sem = j - 1 < 0 ? 0 : dp[i][j - 1];
    //             com = i - moedas[j] < 0 ? 0 : dp[(i - moedas[j])][j];
    //             dp[i][j] = sem + com;
    //         }
    //     }

    //     // ll res = calculaTrco(troco, 0);
    //     cout << dp[troco][moedas.size() - 1] << "\n";
    // }

// int calculaTroco (int troco, int index){
//     if(troco == 0){
//         return 1;
//     } else if (troco < 0 || index == moedas.size()) {
//         return 0;
//     } else {
//         return calculaTroco(troco - moedas[index], index) + calculaTroco(troco, index + 1);
//     }
// }

// int calculaTroco (int troco, int index){
//     if(troco == 0){
//         return 1;
//     } else if (troco < 0 || index == moedas.size()) {
//         return 0;
//     } else {
//         if(dp[troco][index] == -1)
//             dp[troco][index] = calculaTroco(troco - moedas[index], index) + calculaTroco(troco, index + 1);
//         return dp[troco][index];
//     }
// }