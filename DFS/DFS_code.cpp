// simple bfs code
// from dfs of graph- gfg
// example test case:
// Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
// Output: [0, 2, 4, 3, 1]
class Solution {
  public:
  
    void dfsHelper(vector<vector<int>>& adj,int u,vector<bool>& visited,vector<int>& result){
        if(visited[u]==true) return;    // instead of checking here in evry recursive call, one optimization is
                                        // to check before evry recursive call
        
        visited[u]=true;
        result.push_back(u);
        
        for(int i=0;i<adj[u].size();i++){
            dfsHelper(adj,adj[u][i],visited,result);
        }
        
        
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int> result;
        vector<bool> visited(n,false);
        int u=0;
        
        dfsHelper(adj,u,visited,result);
        
        return result;
        
    }
};
