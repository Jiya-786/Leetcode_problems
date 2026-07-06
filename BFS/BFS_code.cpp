// bfs code
class Solution {
  public:
  
    void bfsHelper(vector<vector<int>> &adj,int u,vector<int>& result,vector<bool> visited,queue<int>& q){
        
        while(!q.empty()){
            int a=q.front();
            q.pop();
            
            if(!visited[a]){
                for(int i=0;i<adj[a].size();i++){
                    q.push(adj[a][i]);
                }
                result.push_back(a);
                visited[a]=true;
            }
        }
        
    }
  
    vector<int> bfs(vector<vector<int>> &adj) {
        int n=adj.size();
        // queue<int> q;
        vector<int> result;
        vector<bool> visited(n,false);
        
        int u=0;
        queue<int> q;
        q.push(u);
        // visited[u]=true;
        // result.push_back(u);
        
        bfsHelper(adj,u,result,visited,q);
        
        return result;
    }
};
