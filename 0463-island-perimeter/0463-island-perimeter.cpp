// dfs approach
class Solution {
public:
    int perimeter;

    void dfs(vector<vector<int>>& grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0||j<0||i>=n||j>=m||grid[i][j]==0){
            perimeter++;
            return;
        }
        if(grid[i][j]==-1){
            return;
        }
        grid[i][j]=-1;

        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int i=0; int j=0;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j);
                    return perimeter;
                }
            }
        }
        return -1;
    }
};

// bfs approach 
// class Solution {
// public:
//     int islandPerimeter(vector<vector<int>>& grid) {
//         int perimeter=0;
//         int i=0; int j=0;
//         int n=grid.size();
//         int m=grid[0].size();
//         queue<pair<int,int>> q;

//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==1){
//                     q.push({i,j});
//                 }
//             }
//         }
        

//         while(!q.empty()){
//             auto it=q.front();
//             q.pop();


//         }

//         return perimeter;
//     }

//     void bfs(vector<vector<int>>& grid,int i,int j){

//     }
// };