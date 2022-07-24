#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int maxi(vector<int>& vet, vector<int>& retira, int k, int c, int index) {
    if(k == 0 || index + c >= vet.size()) {
        if(k == 0) {
            int a = 0;
            for(int i = 0; i < retira.size(); i++){
                cout << retira[i] << " ";
                a++;
                if(a == c){
                    cout << "\n";
                    a = 0;
                }
            }
            int sum = 0;
            for(int i = 0; i < vet.size(); i++){
                if(find(retira.begin(), retira.end(), i) == retira.end()){
                    sum += vet[i];
                }
            }
            cout << "\n" << sum << "<\n";
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

    return com > sem ? com : sem;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica
    int n, k, c;
    cin >> n >> k >> c;

    vector<int> cad(n + 1); for(auto & x: cad) { cin >> x; };
    vector<int> retira;

    cout << maxi(cad, retira, k, c, 0) << "\n";

    // vector<vector<int>> dp;

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < c; j++){

    //     }
    // }
}