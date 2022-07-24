#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int casos; cin >> casos;
    for (int i = 0; i < casos; i++){
        string linha; cin >> linha;
        int seg = 0;
        int j = 0;
        //cout << linha << ":\n";
        while(j < linha.size()){
            char c = linha[j];
            //cout << j << ") "<< c <<"\n"; 
            if(c == '_'){
                j += 3;
                seg++;
            } else {
                j++;
            }
        }

        cout << "Caso "<< i + 1 << ": " << seg << "\n";
    }
}