// rule of thumb: Mark on push → every node enters the queue exactly once → O(V + E).
//                Mark on pop → nodes may enter the queue many times → extra work, potentially much more than 
//                              necessary.

// DFS: mark when you enter the recursive call.
// BFS: mark when you enqueue the node 

// dfs approach
// class Solution {
// public:
//     int perimeter=0;
//
//     void dfs(vector<vector<int>>& grid,int i,int j){
//         int n=grid.size();
//         int m=grid[0].size();
//         if(i<0||j<0||i>=n||j>=m||grid[i][j]==0){
//             perimeter++;
//             return;
//         }
//         if(grid[i][j]==-1){
//             return;
//         }
//         grid[i][j]=-1;

//         dfs(grid,i+1,j);
//         dfs(grid,i-1,j);
//         dfs(grid,i,j+1);
//         dfs(grid,i,j-1);
//     }

//     int islandPerimeter(vector<vector<int>>& grid) {
//         int i=0; int j=0;
//         int n=grid.size();
//         int m=grid[0].size();

//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==1){
//                     dfs(grid,i,j);
//                     return perimeter;
//                 }
//             }
//         }
//         return -1;
//     }
// };

// bfs approach 
class Solution {
public:
    int perimeter=0;

    void bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q){
        while(!q.empty()){
            auto it=q.front();
            int i=it.first; int j=it.second; 
            q.pop();
            
            // grid[i][j]=-1;
            if(check(grid,i+1,j))   dir(grid,i+1,j,q);
            if(check(grid,i-1,j))   dir(grid,i-1,j,q);
            if(check(grid,i,j+1))   dir(grid,i,j+1,q);
            if(check(grid,i,j-1))   dir(grid,i,j-1,q);

        }
    }

    void dir(vector<vector<int>>& grid,int i,int j,queue<pair<int,int>>& q){
        q.push({i,j});
        grid[i][j]=-1;
    }

    bool check(vector<vector<int>>& grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0||j<0||i>=n||j>=m||grid[i][j]==0){
            perimeter++;
            return false;
        }
        if(grid[i][j]==-1){
            return false;
        }
        return true;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        // int perimeter=0;
        int i=0; int j=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    grid[i][j]=-1;
                    bfs(grid,q);
                    return perimeter;
                }
            }
        }
        return -1;
    }
};