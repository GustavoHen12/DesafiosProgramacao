#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    ll hh, min, seg;

    cin >> hh >> min >> seg;

    double gr_hh = 360.0 / hh;
    double gr_min = 360.0 / min;
    double gr_seg = 360.0 / seg;

    cout << gcd(hh, gcd(min, seg)) << "\n";

    ll hh_a = 0, min_a = 0, seg_a = 0;
    bool acabou = false;
    while(hh_a < hh){
        if((hh_a*min%hh) == 0 && (hh_a*seg%hh) == 0){
            min_a = hh_a*min/hh;
            seg_a = hh_a*seg/hh;
            cout << hh_a << " " << min_a << " " << seg_a << "\n";
        }
        hh_a++;
    }
}