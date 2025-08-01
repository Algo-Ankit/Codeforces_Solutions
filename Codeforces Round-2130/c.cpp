#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

struct DSU {
    vector<int> p;
    DSU(int n): p(n+1) { iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a, int b){
        a = find(a); b = find(b);
        if(a == b) return false;
        p[b] = a;
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<array<int,3>> segs(n);

        for(int i = 0; i < n; i++){
            cin >> segs[i][0] >> segs[i][1];
            segs[i][2] = i+1;
        }
        
        sort(all(segs), [&](auto &A, auto &B){
            return (A[1]-A[0]) > (B[1]-B[0]);
        });

        DSU dsu(2*n);
        vector<bool> covered(2*n+1, false); 
        vector<int> answer;

        for(auto &S : segs){
            int a = S[0], b = S[1], idx = S[2];
            if(dsu.find(a) == dsu.find(b)) continue;

            int newCov = 0;
            for(int x = a; x < b; x++){
                if(!covered[x]) newCov++;
            }
            if(newCov > 0){
                // 3) accept it
                dsu.unite(a, b);
                for(int x = a; x < b; x++){
                    covered[x] = true;
                }
                answer.push_back(idx);
            }
        }

        // Output the chosen subset
        cout << answer.size() << "\n";
        for(int i : answer) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
