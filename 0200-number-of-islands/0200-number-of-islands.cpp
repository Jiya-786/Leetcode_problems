// // dfs soln 
// class Solution {
// public:
//     int count=0;

//     void dfs(vector<vector<char>>& grid,int i,int j){
//             int n=grid.size();
//             int m=grid[0].size();
//             if(i<0||j<0||i>=n||j>=m||grid[i][j]=='0'){
//                 return;
//             }
//             if(grid[i][j]=='2'){
//                 return;
//             }
//             // count++;
//             grid[i][j]='2';   // Since -1 is not a single character. It is - and 1. 

//             dfs(grid,i+1,j);
//             dfs(grid,i-1,j);
//             dfs(grid,i,j+1);
//             dfs(grid,i,j-1);
// //          count++;
//      }

//     int numIslands(vector<vector<char>>& grid) {
//         // int i=0; int j=0;
//         int n=grid.size();
//         int m=grid[0].size();

//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]=='1'){
//                     count++;
//                     dfs(grid,i,j);                                                            
//                     // return count;
//                 }
//             }
//         }
//         return count;
//     }
// };

// bfs solution
class Solution {
public:
    int count=0;

    void bfs(vector<vector<char>>& grid,queue<pair<int,int>>& q){
            int n=grid.size();
            int m=grid[0].size();
            
            while(!q.empty()){
                auto it=q.front();
                int i=it.first; int j=it.second;
                q.pop();

                helper(grid,i+1,j,q);
                helper(grid,i-1,j,q);
                helper(grid,i,j-1,q);
                helper(grid,i,j+1,q);

            }
     }

     void helper(vector<vector<char>>& grid,int i,int j,queue<pair<int,int>>& q){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0||j<0||i>=n||j>=m||grid[i][j]=='0'){
            return;
        }
        if(grid[i][j]=='2'){
            return;
        }
        q.push({i,j});
        grid[i][j]='2';
    }

    int numIslands(vector<vector<char>>& grid) {
        // int i=0; int j=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    q.push({i,j});
                    bfs(grid,q);
                }
            }
        }
        return count;
    }
};