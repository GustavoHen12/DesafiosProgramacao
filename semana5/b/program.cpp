#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 15;
#define NEUTRAL 1
#define OP(X, Y) ((X) * (Y))
vector<ll> t(2 * N);

ll op_inclusive(ll l, ll r) {
    r++;
    ll left = NEUTRAL, right = NEUTRAL;
    for (l += N, r += N; l < r; l /= 2, r /= 2)
    {
        if (l & 1)
            left = OP(left, t[l++]);
        if (r & 1)
            right = OP(right, t[--r]);
    }
    return OP(left, right);
}

//00000000000-0--000+00000000+-0...0000
//00000000000000-000-00000000--0...0000000+000000000000000000000-0

void set_value(ll i, ll v) {
    t[i += N] = v;
    for (i /= 2; i > 0; i /= 2)
        t[i] = OP(t[i * 2], t[i * 2 + 1]);
}

void build(vector<ll> &src) {
    for (int i = 1; i < src.size(); i++)
        t[N + i] = src[i];
    for (int i = N - 1; i > 0; i--)
        t[i] = OP(t[2 * i], t[2 * i + 1]);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> ve(n+1);

	for(ll i = 1; i <= n; i++) {
        ll num; cin >> num;
        if(num == 0)
            ve[i] = 0;
        else if(num < 0)
            ve[i] = -1;
        else if(num > 0)
            ve[i] = 1;
    };
	
	build(ve);

	for(ll i = 0; i < k; i++){
		char op;
		int aux_a, aux_b;
		cin >> op >> aux_a >> aux_b;

		if(op == 'A'){
            ll num;
            if(aux_b < 0)
                aux_b = -1;
            else if(aux_b > 0)
                aux_b = 1;

			set_value(aux_a, aux_b);
		} else if (op == 'B'){
            // cout << "*";
            ll value = op_inclusive(aux_a, aux_b);
			if(value > 0)
				cout << "+";
			else if (value < 0)
				cout << "-";
			else
				cout << "0";
		}
	}
    cout << "\n";
}


            // ll interval = aux_b - aux_a;
            // cout << "(" << aux_a << " - " << aux_b << ")\n"; 
            // ll value = NEUTRAL;
            // if(interval > 9){
            //     ll end = aux_a + 9;
            //     while(end <= aux_b){
        	// 		ll temp_value = op_inclusive(aux_a, end);
            //         if(temp_value > 0){
            //             value *= 1;
            //         } else if(temp_value < 0) {
            //             value *= -1;
            //         } else if(temp_value == 0) {
            //             cout << "zerou\n";
            //             value = 0;
            //             break;
            //         }

            //         if(end == aux_b)
            //             break;

            //         if(end + 9 < aux_b)
            //             end += 9;
            //         else
            //             end = aux_b;

            //         cout << end << "\n";
            //     }
            // } else {
    		// 	value = op_inclusive(aux_a, aux_b);
            // }