#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int iteracoes; cin >> iteracoes;
    vector<int> queue;
    int time;
    while(iteracoes--){
        cin >> time;
        queue.push_back(time);
    }

    sort(queue.begin(), queue.end());

    // for (auto x : queue) cout << x << " ";
    // cout << "\n";
    cout << queue.size() / 2 << " ";
    cout << (queue[queue.size() / 2] - queue[(queue.size() / 2) - 1]) << "\n";
}