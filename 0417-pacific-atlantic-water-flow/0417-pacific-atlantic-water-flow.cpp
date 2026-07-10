// We can also use just one array for pacific/atlantic and visited instead of using two different arrays but I didn't understand that idea
class Solution {
public:
    void dfs(vector<vector<int>>& heights,int i,int j,vector<vector<int>>& grid,int prev,vector<vector<int>>& visited){

        int n=heights.size();
        int m=heights[0].size();
        if(i<0||j<0||i>=n||j>=m||visited[i][j]==1||prev>heights[i][j]) return;

        if(prev<=heights[i][j]){
            grid[i][j]=1;
        }
        // if(i==0||i==n-1||j==0||j==m-1) grid[i][j]=1;    unnecessary

        prev=heights[i][j];
        visited[i][j]=1;

        dfs(heights,i+1,j,grid,prev,visited);
        dfs(heights,i,j+1,grid,prev,visited);
        dfs(heights,i-1,j,grid,prev,visited);
        dfs(heights,i,j-1,grid,prev,visited);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> pacific(n,vector<int>(m,-1));
        vector<vector<int>> atlantic(n,vector<int>(m,-1));
        vector<vector<int>> visited(n,vector<int>(m,-1));

        int prev=INT_MIN;
        // firt row
        for(int j=0;j<m;j++){
            dfs(heights,0,j,pacific,prev,visited);
            // dfs(heights,0,j,atlantic,prev,visited);
        }
        // We don't need to reset between two pacific calls.
        // Otherwise, it ends up doing extra DFS work over and again. 
        // Because it will erase whatever we visited in the previous TFS call 
        // But we need it.  
        // visited.clear();
        // visited.assign(n, vector<int>(m, -1));
        //first col
        for(int i=0;i<n;i++){
            dfs(heights,i,0,pacific,prev,visited);
            // dfs(heights,i,0,atlantic,prev,visited);
        }
        visited.clear();
        visited.assign(n, vector<int>(m, -1));
        // last row
        for(int j=0;j<m;j++){
            // dfs(heights,n-1,j,pacific,prev,visited);
            dfs(heights,n-1,j,atlantic,prev,visited);
        }
        // visited.clear();
        // visited.assign(n, vector<int>(m, -1));
        //last col
        for(int i=0;i<n;i++){
            // dfs(heights,i,m-1,pacific,prev,visited);
            dfs(heights,i,m-1,atlantic,prev,visited);
        }

        vector<vector<int>> result;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1){
                    result.push_back({i,j});
                } 
            }
        }
        return result;
    }
};