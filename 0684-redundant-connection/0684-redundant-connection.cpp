// BRUTE FORCE
// DFS approach

// My initial thought was to remove each edge and run DFS/BFS to check whether the graph remains connected. That is valid but inefficient. The better viewpoint is to process edges incrementally and check whether a path already exists between the two endpoints.

// DFS/BFS checks this by explicitly searching for a path.
class Solution {
public:

    bool dfs(unordered_map<int,vector<int>>& adj,int u,int v,vector<bool>& visited){
        visited[u]=true;

        if(u==v) return true;

        for(auto& nei:adj[u]){
            if(!visited[nei] && dfs(adj,nei,v,visited)) return true;
        }

        return false;

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,vector<int>> adj;
        vector<int> ans;

        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];

            vector<bool> visited(n,false);

            if(dfs(adj,u,v,visited)){
                ans=edges[i];
                break;
            }
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            
        }
        return ans;
    }
};

// DSU does the same more efficiently: find(u) == find(v) means both nodes already belong to the same component, so the current edge creates a cycle.