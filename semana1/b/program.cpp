#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int size;
    while(cin >> size){
        vector<int> seqA(size, 0);
        ll numErros = 0, seqB;
        // le entrada sequencia A
        for(int i = 0; i < size; i++){
            cin >> seqA[i];
        }
        
        for(int i = 0; i < (size/2); i++){
            cin >> seqB;
            if((seqA[i] + seqA[size-i-1]) != seqB){
                numErros += fabs((seqA[i] + seqA[size-i-1]) - seqB);
            }
        }

        cout << numErros << "\n";
    }
}