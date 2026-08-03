// sort the first array in ascending order and the 2nd array and
// descending order and we will keep replacing the smallest elements
// of the first array with the largest elements of the second array K
// times and before K in case elements in the first array become greater
// than the elements in the secondary we will stop we will not do kmoves
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a.begin(),a.end());
        sort(b.rbegin(),b.rend());
        
        for(int i=0;i<k;i++){
            if(a[i]<b[i]) swap(a[i],b[i]);
            else break;
        }
        int ans=0;
        for(int x:a){
            ans+=x;
        }
        cout<<ans<<"
";
        
    }
return 0;
}