#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast_io ios::sync_with_stdio(false); cin.tie(0);

int get_max_score(vi &S) {
    vector<int> freq(60, 0);
    for (int x : S) freq[x]++;
    
    int score = 0;
    while (true) {
        int k = 0;
        while (freq[k] > 0) k++;
        if (k == 0) break;
        for (int i = 0; i < k; i++) {
            freq[i]--;
        }
        score += k;
    }
    for (int v = 0; v < (int)freq.size(); v++) {
        if (freq[v] > 0) score += v * freq[v];
    }
    return score;
}

int main() {
    fast_io;
    
    int t; 
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vi S(n);
        for (int &x : S) cin >> x;
        cout << get_max_score(S) << "\n";
    }
    return 0;
}
