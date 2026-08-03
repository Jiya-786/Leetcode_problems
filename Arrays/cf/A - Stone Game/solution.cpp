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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int minI=0;int maxI=0;
        
        for(int i=0;i<n;i++){
            if(a[i]<a[minI]) minI=i;
            else if(a[i]>a[maxI]) maxI=i;
        }
        int left=min(minI,maxI);
        int right=max(minI,maxI);
        
        int bothLeft=(right+1);
        int bothRight=(n-left);
        int Sides=(left+1)+(n-right);
        
        int ans=min({bothLeft,bothRight,Sides});
        cout<<ans<<"
";
        }
return 0;
}