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
int n; 
int totalSum = 0, totalSumTemp = 0;

void encontraPrimos(){
    // auto t1 = high_resolution_clock::now();

    vector<bool> numState(n+1, true);
    vector<bool> listPrimos(n+1, true);
    for(ll i = 2; i*i <= n; i++){
        if(numState[i]) {
            for(ll j = i * i; j <= n; j+= i){
                numState[j] = false;
                listPrimos[j] = false;
            }
        }
    }

    if(n >= 4){
        for(int i = 2; i <= n; i++){
            if(listPrimos[i]){
                int diff  = n - i;
                if(diff > 1 && listPrimos[diff]){
                    //cout << i << " + " << diff << "\n";
                    totalSum++;
                    listPrimos[diff] = false;
                } 
            }
        }
    }

    // vector<int> primos;
    // //int sz = 0;
    // int lastIndex = -1;
    // for(int i = 2; i <= n; i++){
    //     if(numState[i]){
    //         bool somou = false;
            
    //         if(i+i == n){
    //             totalSumTemp++;
    //         }
    //         int sz = lastIndex >= 0 ? lastIndex : (primos.size() - 1);
    //         for(int j = sz; j >= 0; j--) {
    //             if(numState[primos[j]]){
    //                 int sum = i + primos[j];
    //                 if(sum < n){
    //                     break;
    //                 } else if(sum == n) {
    //                     //cout << i << " + " << primos[j] << "\n";
    //                     totalSumTemp++;
    //                     somou = true;
    //                     lastIndex = j;
    //                     numState[primos[j]] = false;
    //                     break;
    //                 }
    //             }
    //         }
    //         if(!somou){
    //             primos.push_back(i);
    //         }
    //     }
    // }

    // auto t2 = high_resolution_clock::now();
    // duration<double, std::milli> ms_double = t2 - t1;
    // std::cout << ms_double.count() << "ms\n";

    // for(int i = 2; i <= n; i++)
    //     if(numState[i])
    //         primos.push_back(i);
    // t1 = high_resolution_clock::now();

    
    // t2 = high_resolution_clock::now();
    // duration<double, std::milli> ms_double_2 = t2 - t1;
    // std::cout << ms_double_2.count() << "ms\n";

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    encontraPrimos();
    cout << totalSum <<"\n";
    // if(totalSum != totalSumTemp){
    //     cout << n << " >" << totalSum << "  " << totalSumTemp << "\n";
    // }
}