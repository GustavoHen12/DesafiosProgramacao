#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int iteracoes; cin >> iteracoes;
    list<int> fifo, lifo;
    priority_queue<int, vector<int>, less<int>> pq;

    bool fifo_b = false, lifo_b = false, pq_b = false, unknow = false;
    while(iteracoes--){
        int op, idade;
        cin >> op >> idade;

        if(op == 0){
            fifo.push_back(idade);
            lifo.push_back(idade);
            pq.push(idade);
        } else {
            //cout << "(" << idade << ") " << *(fifo.begin()) << "  " << *(--lifo.end()) << "   " << pq.top() << "\n";
            if(*(fifo.begin()) == idade){
                fifo.pop_front();
                fifo_b = true;
            }
            if(*(--lifo.end()) == idade) {
                lifo.pop_back();
                lifo_b = true;
            }
            if(pq.top() == idade) {
                pq.pop();
                pq_b = true;
            }

            if(!fifo_b && !lifo_b && !pq_b){
                unknow = true;
            }
        }
    }

    //cout << fifo_b << "  " << lifo_b << "   " << pq_b << "\n";

    if(!fifo.empty() && !lifo.empty() && !pq.empty()) {
        cout << "unknown" << "\n";
    } else if (fifo.empty() && !lifo.empty() && !pq.empty()) {
        cout << "fifo" << "\n";
    } else if (!fifo.empty() && lifo.empty() && !pq.empty()) {
        cout << "lifo" << "\n";
    } else if (!fifo.empty() && !lifo.empty() && pq.empty()) {
        cout << "priority" << "\n";
    } else {
        cout << "ambiguous" << "\n";
    }
}