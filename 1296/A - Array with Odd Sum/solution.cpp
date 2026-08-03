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
        int totSum=0;
        
        for(int i=0;i<n;i++){
            cin>>a[i];
            totSum+=a[i];
        }
        bool hasOdd=false;
        bool hasEven=false;
        
        for(int x:a){
            if(x%2==0) hasEven=true;
            else hasOdd=true;
        }
        
        if(totSum%2==1||(hasOdd && hasEven)) cout<<"YES
";
        else cout<<"NO
";
        
    }
    return 0;
}