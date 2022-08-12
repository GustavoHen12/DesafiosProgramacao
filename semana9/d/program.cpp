#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica
    int n, m;
    cin >> n >> m;
    vector<vector<int>> data(n);
    vector<bool> source(n+1, true);
    for(int i = 0; i < n; i++){
        int elements; cin >> elements;
        while (elements--){
            int el; cin >> el;
            (data[i]).push_back(el);
        }
        sort((data[i]).begin(), (data[i]).end());
        for(int j = 0; j < i; j++){
            if(source[j]){
                if(includes((data[i]).begin(), (data[i]).end(), (data[j]).begin(), (data[j]).end())){
                    source[i] = false;
                    break;
                } 
                if(includes((data[j]).begin(), (data[j]).end(), (data[i]).begin(), (data[i]).end())){
                    source[j] = false;
                } 
            }
        }         
    }

    for(int i = 0; i < n; i++){
        if(source[i]){
            cout << i << "\n";
        }
    }
}