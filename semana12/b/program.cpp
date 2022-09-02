#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool caracterValido(char c, bool validaNumero){
    // cout << c << " " << c - 0 << "\n";
    if(c >= 97 && c <= 122)
        return true;
    
    if(validaNumero)
        if(c >= 48 && c <= 57)
            return true;
    
    return false;
}
bool valido(string email){
    int arroba = email.find('@');
    
    if(arroba == string::npos || arroba == 0){
        return false;
    }

    // Valida se o primeiro não é digito
    if(!caracterValido(email[0], false)){
        return false;
    }

    // Valida o restante ate o arroba
    for(int i = 0; i < arroba; i++)
        if(!caracterValido(email[i], true)){
            return false;
        }
    
    // Valida se acaba com ufpr.br
    string fim = email.substr(arroba + 1, email.size());
    string emailValido = "ufpr.br"; 
    while(fim != emailValido && fim.length() > emailValido.length()){
        int ponto = fim.find('.');
        for(int i = 0; i < ponto; i++)
            if(!caracterValido(fim[i], true)){
                return false;
            }
        fim.erase(0,  ponto + 1);
    }

    return fim == emailValido;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    int count; cin >> count;
    vector<pair<string, int>> result;
    while(count--){
        string email;
        getline(cin, email);

        if(valido(email)){
            int index = 0;
            for(int i = 0; i < result.size(); i++){
                if(result[i].first == email){
                    result[i].second++;
                    index = i;
                    break;
                }
            }

            if(index == 0){
                pair<string, int> p = make_pair(email, 1);
                result.push_back(p);
            }

            cout << result[index].second << "\n";
        }
    }
}