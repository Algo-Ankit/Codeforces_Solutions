#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        
        vi a(n);
        int c0 = 0, c1 = 0, c2 = 0;
        for(int &x : a){
            cin >> x;
            if(x==0) ++c0;
            else if(x==1) ++c1;
            else ++c2;
        }
        int sum0 = c1 + 2*c2;

        if(s < sum0){
            for(int x : a) cout << x << ' ';
            cout << "\n";
            continue;
        }
        if(s == sum0){
            cout << "-1\n";
            continue;
        }

        int T = s - sum0;
        if(T != 1){
            
            cout << "-1\n";
            continue;
        }
        for(int i = 0; i < c0; ++i) cout << 0 << ' ';
        for(int i = 0; i < c2; ++i) cout << 2 << ' ';
        for(int i = 0; i < c1; ++i) cout << 1 << ' ';
        cout << "\n";
    }

    return 0;
}
