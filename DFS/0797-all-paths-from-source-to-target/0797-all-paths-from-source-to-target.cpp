class Solution {
public:

    void dfs(vector<vector<int>>& adj,int x,vector<int>& temp,vector<vector<int>>& result,int target){
        temp.push_back(x);
        if(x==target){
                result.push_back(temp);
                temp.pop_back();          // backtrack. if the target was found then we explore other neighbours 
                                          // of the node to see if we get another path
                return;
        }
        for(int v:adj[x]){
            dfs(adj,v,temp,result,target);
        }
        temp.pop_back();                 // backtrack
                                         // note its imp to understand that back-track will happen after dfs of that entire node is completed ie if dfs was done on 3 then all its neighbours will also be explored, if target was found, it would be pushed into result and returned and then 3 will get backtracked.
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        vector<vector<int>> result;
        int n=adj.size();
        
        for(int x:adj[0]){
            vector<int> temp;
            temp.push_back(0);
            dfs(adj,x,temp,result,n-1);
        }
        return result;
    }
};