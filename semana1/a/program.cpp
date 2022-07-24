#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    string numA, numB;
    int count;
    cin >> count;

    while(count--){
        cin >> numA >> numB;
        char charA = numA.back();
        char charB = numB.back();
        int a = charA - '0';
        int b = charB - '0';
        // cout << numA << " " << charA << ": " << a << "\n";
        // cout << numB << " " << charB << ": " << b << "\n";
        if((a+b) % 2 == 1){
            cout << "NAO PARCEIROS" << "\n";
        } else {
            cout << "PARCEIROS" << "\n";
        }
    }
}