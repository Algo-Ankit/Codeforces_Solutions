#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct BIT
{
    int n;
    vector<int> f;
    BIT(int _n) : n(_n), f(n + 1, 0) {}
    void update(int i)
    {
        for (; i <= n; i += i & -i)
            f[i]++;
    }
    int query(int i)
    {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += f[i];
        return s;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];
        BIT bit(2 * n);
        ll inv = 0;
        for (int x : p)
        {
            int q = 2 * n - x;
            ll total = bit.query(2 * n);
            ll c0 = total - bit.query(x);
            ll c1 = total - bit.query(q);
            if (c0 <= c1)
            {
                inv += c0;
                bit.update(x);
            }
            else
            {
                inv += c1;
                bit.update(q);
            }
        }
        cout << inv << " \n";
    }
    return 0;
}
