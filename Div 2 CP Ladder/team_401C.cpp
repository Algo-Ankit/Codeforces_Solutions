#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    fast_io;

    int n, m;
    cin >> n >> m;
    string s = "";
    if (m > 2 * (n + 1) || m < n - 1)
    {
        cout << -1;
        return 0;
    }
    while (n > 0 || m > 0)
    {
        // CASE 1: m>n
        if (m > n)
        {
            if (m >= 2)
            {
                s += "11";
                m -= 2;
            }
            else
            {
                s += "1";
                m--;
            }
            if (n > 0)
            {
                s += "0";
                n--;
            }
        }
        else if (n > m)
        {
            s += "0";
            n--;
            if (m > 0)
            {
                s += "1";
                m--;
            }
        }
        else
        {
            if (m > 0)
            {
                s += "1";
                m--;
            }
            if (n > 0)
            {
                s += "0";
                n--;
            }
        }
    }
    cout << s;
    return 0;
}