#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int> coins(n);
        
        int totSum=0;
        for(int i=0;i<n;i++){
            cin>>coins[i];
            totSum+=coins[i];
        }
        sort(coins.rbegin(),coins.rend());
        int twinSum=totSum;
        int mySum=0;
        int count=0;
        
        for(int x:coins){
            mySum+=x;
            twinSum-=x;
            count++;
            if(mySum>twinSum) break;
        }
        
        
        cout<<count;
        
        
    }
    return 0;
}