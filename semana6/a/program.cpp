#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define MAX 12345

ll graf[MAX][MAX];
int n, k;
bool visitou[MAX];

int busca(int raiz){
    int c = 0;
    stack<ll> stk;
    stk.push(raiz);
    while(!stk.empty()){
        int nd = stk.top();
        stk.pop();
        for(int i = 0; i < n; i++){
            if(graf[nd][i] == 1 && !visitou[i]){
                c++;
                visitou[i] = true;
                stk.push(i);
            }
        }
    }

    return c;
}

int explora(int raiz){    
    int c = 0;
    for(int i = 0; i < n; i++){
        if(!visitou[i]){
            c++;
            busca(i);
        }
    }
    return c;
}

// int estado[MAX];
// int explora(int raiz){
//     int c = 0;
//     vector<ll> stk;
//     stk.push_back(raiz);
//     estado[raiz] = 1;
//     while(!stk.empty()){
//         int nd = *(stk.end() - 1);
//         stk.pop_back();
//         for(int i = 0; i < n; i++){
//             if(graf[nd][i] == 1 && estado[i] == 0){
//                 estado[n] = 1;
//                 stk.push_back(i);
//             }
//         }
//         estado[nd] = 2;
//     }

//     return c;
// }

// int componente(){
//     int c = 0;
//     for(int i = 0; i < n; i++){
//         if(estado[i] == 0){
//             c++;
//             explora(i);
//         }
//     }

//     return c;
// }

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;

    memset(graf, 0, MAX*MAX);
    memset(visitou, 0, MAX);

    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        graf[a][b] = 1;
        graf[b][a] = 1;
        // cout << a << "  " << b << "\n";
    }

    cout << explora(0) << "\n";


}

