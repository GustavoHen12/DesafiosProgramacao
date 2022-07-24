#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int iteracoes; cin >> iteracoes;
    stack<pair<int, char>> queue;
    bool valido = true;

    while(iteracoes-- && valido){
        pair<int, char> torre;
        cin >> torre.first >> torre.second;
        
//        cout << torre.first << " - " << torre.second << "\n";
    
        if(queue.empty()){
            queue.push(torre);
        } else {
            pair<int, char> tp = queue.top();

//            cout << "topo: " << tp.first << " - " << tp.second << "\n";

            if(tp.first > torre.first){
                queue.push(torre);
            } else if(tp.first == torre.first){
                if(tp.second == 'L' && torre.second == 'O'){
                    queue.pop();
                } else {
                    valido = false;
                }
            } else {
                valido = false;
            }
        } 
    }

    if(valido && queue.empty()){
        cout << "S\n";
    } else {
        cout << "N\n";
    }

}