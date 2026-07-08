// just dfs while maintaining max time
class Solution {
public:

    // make note of this wrong dfs
    // The issue is that the recursion should return the maximum time from a node to any employee in its subtree, 
    //  rather than trying to maintain a single time variable passed down the recursion.

    // int dfs(vector<vector<int>>& adj,int u,vector<int>& informTime,int time){
    //     time=max(time,time+informTime[u]);

    //     for(int v:adj[u]){
    //         dfs(adj,v,informTime,time);
    //     }

    //     return time;
    // }

    void dfs(vector<vector<int>>& adj,int u,vector<int>& informTime,int currTime,int& maxTime){
        maxTime=max(maxTime,currTime);

        for(int v:adj[u]){
            dfs(adj,v,informTime,currTime+informTime[u],maxTime);
        }

    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // int time=0;

        vector<vector<int>> adj(n);      // need to decplare adj size since we're doing adj[manager[i]].push_back
                                         // (i), ow gives out of bounds 

        int m=manager.size();
        for(int i=0;i<m;i++){
            if(i==headID) continue;   // since if headID then manager[headID]=-1, gives seg-fault
            adj[manager[i]].push_back(i);
        }

        int maxTime=0;
        dfs(adj,headID,informTime,0,maxTime);    // should pass maxTime, can't pass 0, since passing by ref 
        return maxTime;

        
    }
};