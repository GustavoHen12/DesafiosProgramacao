#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string materia;
    while(cin >> materia){
        ll hora, min;
        cin >> hora >> min;
        min += (hora * 60);

        if(min <= 600){
            cout << "Abel deve cursar " << materia << "\n";
        } else {
            cout << "Abel deve cancelar " << materia << "\n";
        }
    }
}