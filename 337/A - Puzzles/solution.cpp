#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    // cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vector<int> f(m);
        
        for(int i=0;i<m;i++){
            cin>>f[i];
        }
        sort(f.begin(),f.end());
        
        int minDiff=INT_MAX;
        
        int i=0; int j=n-1;
        while(i<m && j<m){
            minDiff=min(minDiff,f[j]-f[i]);
            i++; j++;
        }
        cout<<minDiff;
        
    }
    return 0;
}