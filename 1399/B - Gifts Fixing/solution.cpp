#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        int minA=INT_MAX; int minB=INT_MAX;
        
        for(int i=0;i<n;i++){
            cin>>a[i];
            minA=min(minA,a[i]);
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            minB=min(minB,b[i]);
        }
        
        long long ans=0;
        
        for(int i=0;i<n;i++){
            int candyDiff=a[i]-minA;
            int orangeDiff=b[i]-minB;
            
            ans+=max(candyDiff,orangeDiff);
        }
        cout<<ans<<"
";
    
    }
    return 0;
}