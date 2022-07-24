#include <bits/stdc++.h>

// #include <chrono>
// void long_operation()
// {
//     /* Simulating a long, heavy operation. */

//     using namespace std::chrono_literals;
//     std::this_thread::sleep_for(150ms);
// }
// using std::chrono::high_resolution_clock;
// using std::chrono::duration_cast;
// using std::chrono::duration;
// using std::chrono::milliseconds;

using namespace std;
using ll = long long;

const int M = 1e9;
int n; int totalSum = 0;

void encontraPrimos(){
    // auto t1 = high_resolution_clock::now();

    vector<bool> numState(n+1, true);
    vector<bool> numStateCp(n+1, true);
    for(ll i = 2; i*i <= n; i++){
        if(numState[i]) {
            for(ll j = i * i; j <= n; j+= i){
                numState[j] = false;
                numStateCp[j] = false;
            }
        }
    }
    // auto t2 = high_resolution_clock::now();
    // duration<double, std::milli> ms_double = t2 - t1;
    // std::cout << ms_double.count() << "ms\n";

    // for(int i = 2; i <= n; i++)
    //     if(numState[i])
    //         primos.push_back(i);
    // t1 = high_resolution_clock::now();

    vector<int> primos;
    //int sz = 0;
    int lastIndex = -1;
    for(int i = 2; i <= n; i++){
        if(numState[i]){
            bool somou = false;
            
            if(i+i == n){
                totalSum++;
            }
            int sz = lastIndex >= 0 ? lastIndex : (primos.size() - 1);
            for(int j = sz; j >= 0; j--) {
                if(numState[primos[j]]){
                    int sum = i + primos[j];
                    if(sum < n){
                        break;
                    } else if(sum == n) {
                        totalSum++;
                        somou = true;
                        lastIndex = j;
                        numState[primos[j]] = false;
                        break;
                    }
                }
            }
            if(!somou){
                primos.push_back(i);
            }
        }
    }
    
    // t2 = high_resolution_clock::now();
    // duration<double, std::milli> ms_double_2 = t2 - t1;
    // std::cout << ms_double_2.count() << "ms\n";

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;

    encontraPrimos();

    // for (int i = 0; i < primos.size(); i++){
    //     for(int j = i; j < primos.size(); j++) {
    //         int sum = primos[i] + primos[j]; 
    //         if(sum > n){
    //             break;
    //         } else if(sum == n) {
    //             totalSum++;
    //             break;
    //         }
    //     }
    // }

    cout << totalSum << "\n";
}