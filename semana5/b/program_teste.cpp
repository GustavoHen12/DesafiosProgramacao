#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 15;
#define NEUTRAL 1
#define OP(X, Y) ((X) * (Y))
vector<int> t(2 * N);
int op_inclusive(int l, int r)
{
    r++;
    int left = NEUTRAL, right = NEUTRAL;
    for (l += N, r += N; l < r; l /= 2, r /= 2)
    {
        if (l & 1)
            left = OP(left, t[l++]);
        if (r & 1)
            right = OP(right, t[--r]);
    }
    return OP(left, right);
}
void set_value(int i, int v)
{
    t[i += N] = v;
    for (i /= 2; i > 0; i /= 2)
        t[i] = OP(t[i * 2], t[i * 2 + 1]);
}
void build(vector<int> &src)
{
    for (int i = 1; i < src.size(); i++)
        t[N + i] = src[i];
    for (int i = N - 1; i > 0; i--)
        t[i] = OP(t[2 * i], t[2 * i + 1]);
}

int main()
{
    int n;
    cin >> n;
    vector<int> src(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> src[i];
    }
    build(src);
    char op;
    int a, b, v, i;
    string s;
    while (cin >> op)
        if (op == 'A')
        {
            cin >> i >> v;
            set_value(i, v);
        }
        else if (op == 'B')
        {
            cin >> a >> b;
            cout << op_inclusive(a, b) << "\n";
        }
        else
            getline(cin, s);
}
