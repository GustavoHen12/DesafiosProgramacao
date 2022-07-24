#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<vector<int>> dp;

int maxi(vector<int>& vet, vector<int>& retira, int k, int c, int index) {
    if(dp[index][k] != -45){
        return dp[index][k];
    } else {
        if(k == 0 || index + c >= vet.size()) {
            if(k == 0) {
                int a = 0;
                int sum = 0;
                for(int i = 0; i < vet.size(); i++){
                    if(find(retira.begin(), retira.end(), i) == retira.end()){
                        sum += vet[i];
                    }
                }
                return sum;
            } else {
                return 0;
            }
        }
        for(int i = index; i < index + c; i++){
            retira.push_back(i);
        }
        int com = maxi(vet, retira, k-1, c, index + c);    
        
        for(int i = index; i < index + c; i++){
            retira.pop_back();
        }
        int sem = maxi(vet, retira, k, c, index + 1);

        dp[index][k] = com > sem ? com : sem;
        return com > sem ? com : sem;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica
    int n, k, c;
    cin >> n >> k >> c;

    vector<int> cad(n + 1); for(auto & x: cad) { cin >> x; };
    vector<int> retira;

    for(int i = 0; i < n+1; i++){
        vector<int> inter(k+1, -45);
        dp.push_back(inter);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < c; j++){
            
        }
    }
}