#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int iteracoes, limite; cin >> iteracoes >> limite;
    set<string> meias;
    string meia;
    bool ultrapassou_limite = false;
    while(iteracoes--){
        cin >> meia;
        if(meias.find(meia) != meias.end()){
            meias.erase(meia);
        } else {
            meias.insert(meia);
        }

        if(meias.size() >= limite)
            ultrapassou_limite = true;
    }

    if(ultrapassou_limite)
        cout << "7.18808\n";
    else
        cout << "3.14159\n";
}