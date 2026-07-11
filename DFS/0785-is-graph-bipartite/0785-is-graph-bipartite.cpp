// classic case of FAIL-FAST,PASS-LAST
class Solution {
public:

    bool dfs(vector<vector<int>>& adj,int i,int color,vector<int>& visited){
        // colour current node 
        visited[i]=color;

        // now check neighbours 
        for(int v:adj[i]){
            if(visited[v]==color) return false;
        else if(visited[v]==-1){                   // only do dfs is unvisted, becuase if a node is correctly 
                                                   // covered, it is definitely visited before, and hence
            if(dfs(adj,v,1-color,visited)==false) return false;
        }                                          //main thing is return false only when false, otherwise if the 
                                                  // entire thing never returned false, just return true. its confusing to think of when to return true also, never works 
        }
        return true;
        
    }

    bool isBipartite(vector<vector<int>>& adj) {
       int n=adj.size(); 
       vector<int> visited(n,-1);
    //    return dfs(adj,0,1,visited);
       for(int i=0;i<n;i++){
        for(int v:adj[i]){
            if(visited[v]==-1){
                if(!dfs(adj,v,1,visited)) return false;       // note: not just return. return with and if
            }
        }
       }
       return true;
    }
};

