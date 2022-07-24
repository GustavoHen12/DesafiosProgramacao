#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> s (20);
vector<int> index_s (21);
vector<bool> chosen (21);
vector<pair<int, int>> list_restr;
int n, t;

bool seqInvalida() {
    for(pair<int, int> rest : list_restr){
        if(index_s[rest.first] != -1 && index_s[rest.second] != -1 && (index_s[rest.first] > index_s[rest.second])){
            return true;
        }
    }

    return false;
}
void gen(int k) {
    if(seqInvalida()){
        return;
    }
    if (k == n) {

        for (int i = 0; i < n; i++) {
            if(i > 0) cout << " ";
            cout << s[i];
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!chosen[i]) {
            chosen[i] = 1;
            s[k] = i;
            index_s[i] = k;
            // cout << i << " - " << k << " - " << index_s[i] << "> " << k;
            // for (int j = 0; j < n; j++) {
            //     cout << ": " << s[j] << " (" << index_s[s[j]] << ")"<< " ";
            // }
            // cout << "\n";
            gen(k+1);
            chosen[i] = 0;
            index_s[i] = -1;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tamanho, restricoes; cin >> n >> restricoes;
    vector<int> list;

    int a, b;
    pair<int, int> p;
    while(restricoes--){
        cin >> a >> b;
        p = make_pair(a, b);
        list_restr.push_back(p);
    }

    for(int i = 0; i <= n; i++){
        index_s[i] = -1;
    }

    gen(0);
}