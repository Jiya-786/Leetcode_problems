class Solution {
public:

    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& visited){
        int n=grid.size();
        int m=grid[0].size();
        if (i<0||j<0||i>=n||j>=m||visited[i][j]==1) return;    // this has to be first since we are writing the   
                                                               // if statement by using i and j, so i&j have to 
                                                               // be valid.    

        if(grid[i][j]==1){                                      
        // int n=grid.size();
        // int m=grid[0].size();
        // if(visited[i][j]==1||i<0||j<0||i>=n||j>=m) return;   // this won't work cuz before visited[i][j]==1, 
                                                                // i&j have to be valid
        if(i<0||j<0||i>=n||j>=m||visited[i][j]==1) return;

        grid[i][j]=0;
        visited[i][j]=1;

        dfs(grid,i+1,j,visited);
        dfs(grid,i,j+1,visited);
        dfs(grid,i-1,j,visited);
        dfs(grid,i,j-1,visited);}
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<int>> visited(n,vector<int>(m,0));

        //first col
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                vector<vector<int>> visited(n,vector<int>(m,0));
                dfs(grid,i,0,visited);
            }
        }
        //first row
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                vector<vector<int>> visited(n,vector<int>(m,0));
                dfs(grid,0,i,visited);
            }
        }
        //last col
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1){
                vector<vector<int>> visited(n,vector<int>(m,0));
                dfs(grid,i,m-1,visited);
            }
        }
        //last row
        for(int i=0;i<m;i++){
            if(grid[n-1][i]==1){
                vector<vector<int>> visited(n,vector<int>(m,0));
                dfs(grid,n-1,i,visited);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]) count++;
            }
        }
        return count;
    }
};