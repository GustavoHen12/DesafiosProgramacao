#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool lutaTradicional (string luta){
    if(luta == "idjassu" || luta == "galhofa" || luta == "aipenkuit") {
        return true;
    }

    return false;
}

bool sortbysec(const tuple<int, string, int, int, int>& a, const tuple<int, string, int, int, int>& b){
    if(lutaTradicional(get<1>(a)) && !lutaTradicional(get<1>(b))){
        return 2 < 3;
    } else if (!lutaTradicional(get<1>(a)) && lutaTradicional(get<1>(b))) {
        return 2 > 3;
    }

    if(get<2>(a) >= 780 && get<2>(b) < 780) {
        return 2 < 3;
    } else if (get<2>(b) >= 780 && get<2>(a) < 780) {
        return 2 > 3;
    }


    if(get<3>(a) != get<3>(b)){
        return (get<3>(a) > get<3>(b));
    }

    return (get<4>(a) < get<4>(b));
}
  
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int iteracoes, limite; cin >> iteracoes >> limite;
    vector<tuple<int, string, int, int, int>> lista;
    int i = 1;
    while(i <= iteracoes){
        tuple<int, string, int, int, int> candidato;
        string luta;
        char c;
        int hora, min, horario, experiencia, classificacao;
        cin >> luta >> hora >> c >> min >> experiencia >> classificacao;

        horario = (hora*60) + min;

        candidato = make_tuple(i, luta, horario, experiencia, classificacao);
        lista.push_back(candidato);
        
        i++;
    }

    // for(int i = 0; i < lista.size(); i++){
    //     cout << get<0>(lista[i]) << " " << get<1>(lista[i]) << " " << get<2>(lista[i]) << " " << get<3>(lista[i]) << " " << get<4>(lista[i]) << "\n";
    // }

    sort(lista.begin(), lista.end(), sortbysec);

    // cout << "---\n";
    // for(int i = 0; i < lista.size(); i++){
    //     cout << get<0>(lista[i]) << " " << get<1>(lista[i]) << " " << get<2>(lista[i]) << " " << get<3>(lista[i]) << "\n";
    // }
    // cout << "---\n";


    for(int i = 0; i < limite; i++){
        cout << get<0>(lista[i]) << "\n";
    }
}