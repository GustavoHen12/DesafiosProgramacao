#include <bits/stdc++.h>

using namespace std;
using ll = long long;
  
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int iteracoes; cin >> iteracoes;
    list<int> lt;
	list<int>::iterator it = lt.begin();

    bool primeiro = true;
	while(iteracoes--){
		char op;
		int aux_a, aux_b;
        cin >> op;
        //cout << op << " ----\n ";
        switch (op) {
            case 'm':
                cin >> aux_a;
                advance(it, aux_a);
                break;
            case 'i':
                cin >> aux_a >> aux_b;
                // cout << aux_a << " - " << aux_b << endl ;
                for(int i = 0; i < aux_a; i++){
                    lt.insert(it, aux_b);
                    it--;			
                }

                if(primeiro){
                    it = lt.begin();
                    primeiro = false;
                }
                break;
            case 'd':
                it = lt.erase(it);
                break;
            case 'q':
    			cout << *it << endl;
                break;
            default:
                break;
        }

        // cout << "(" << lt.size() << ")" << "| ";
        // for(auto x: lt) cout << x << " ";
        // cout << "| => ";
        // cout << *it << endl;
	}
}