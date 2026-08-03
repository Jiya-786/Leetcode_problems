#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    // cin >> t;
    while (t--) {
        vector<vector<int>> grid(5,vector<int>(5));
        int row=0; int col=0;
        
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                scanf("%d",&grid[i][j]);
                if(grid[i][j]==1){
                    row=i; col=j;
                }
            }
        }
        int ans=0;
        // when using 0-based indexing the center will be 2,2 not 3,3
        ans= abs(row-2)+abs(col-2);
        
        cout<<ans;
        
    }
    return 0;
}