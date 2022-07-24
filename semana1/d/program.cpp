#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int count;
    cin >> count;
    bool iniciou = false, possivel_fim = false;
    int ultimo_fim = 0, sequencia_a = 0, tamanho_poli = 0, tamanho_total = 0;
    char letra;
    while(count--){
        cin >> letra;
        if(letra == 'A'){
            sequencia_a++;
        } else {
            sequencia_a = 0;
        }

        if(iniciou){
            tamanho_total++;
        }

        if(sequencia_a >= 7) {
            if(iniciou){
                possivel_fim = true;
                tamanho_poli = tamanho_total + 7;
            } else {
                iniciou = true;
                //sequencia_a = 0;
                tamanho_poli = 7;
            }
        }
    }

    cout << tamanho_poli << "\n";
}