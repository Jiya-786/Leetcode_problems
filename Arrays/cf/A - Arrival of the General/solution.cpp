#include <bits/stdc++.h>
using namespace std;
 
int main(void) {
    int t = 1;
    /* scanf("%d", &t); */
    while (t--) {
        int n;
        scanf("%d",&n);
 
        vector<int> h(n);
        for(int i=0;i<n;i++){
            scanf("%d",&h[i]);
        }
 
    int maxI=0;
    for(int i=0;i<n;i++){
        if(h[i]>h[maxI]) maxI=i;
    }
 
    int minI=n-1;
    for(int i=n-1;i >= 0;i--){
        if(h[i]<h[minI]) minI=i;
    }
 
    int maxSwaps=maxI;
    int minSwaps=(n-1)-minI;
 
    int ans=maxSwaps+minSwaps;
 
    if(maxI>minI) ans--;
 
    cout << ans;
    }
    return 0;
}