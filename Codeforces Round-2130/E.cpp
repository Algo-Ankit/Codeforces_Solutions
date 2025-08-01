#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t; // Number of test cases
    
    for (int test = 0; test < t; ++test) {
        int n;
        cin >> n; // Length of the bracket sequence
        
        vector<int> f(n + 1, 0); // f[k] is the number of regular subsequences in prefix of length k
        vector<int> g(n + 1, 0); // g[k] = f[k] - f[k-1]
        
        // Step 1: Query all prefixes
        for (int k = 1; k <= n; ++k) {
            cout << "? " << k;
            for (int i = 1; i <= k; ++i) {
                cout << " " << i;
            }
            cout << endl;
            cout.flush();
            cin >> f[k];
        }
        
        // Step 2: Compute g_k to infer characters
        for (int k = 1; k <= n; ++k) {
            g[k] = f[k] - f[k - 1];
        }
        
        // Step 3: Construct initial sequence based on g_k
        string s(n, ' ');
        vector<int> ambiguous;
        for (int k = 1; k <= n; ++k) {
            if (g[k] > 0) {
                s[k - 1] = ')'; // New regular subsequence ends here
            } else {
                s[k - 1] = '('; // Tentative assignment, may need verification
                ambiguous.push_back(k - 1);
            }
        }
        
        // Step 4: Resolve ambiguous positions with additional queries
        // For simplicity, query each ambiguous position individually (up to 50 extra queries)
        for (int pos : ambiguous) {
            cout << "? 1 " << (pos + 1) << endl;
            cout.flush();
            int result;
            cin >> result;
            if (result > 0) {
                s[pos] = '('; // Should already be '('
            } else {
                // Check if it could be ')' by pairing with previous
                if (pos > 0) {
                    cout << "? 2 " << pos << " " << (pos + 1) << endl;
                    cout.flush();
                    cin >> result;
                    if (result > 0) {
                        s[pos] = ')';
                    } else {
                        s[pos] = '('; // Default to '(' if unclear
                    }
                }
            }
        }
        
        // Step 5: Output the final sequence
        cout << "! " << s << endl;
        cout.flush();
    }
    
    return 0;
}