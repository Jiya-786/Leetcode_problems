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
        int wrongEven=0; int wrongOdd=0;
        
        for(int i=0;i<n;i++){
            if(i%2!=0 && a[i]%2==0) wrongEven++;
            else if(i%2==0 && a[i]%2!=0) wrongOdd++;
        }
        if(wrongEven!=wrongOdd) cout<< -1<<"
";
        else cout<<wrongEven<<"
";
        
    }
    return 0;
}