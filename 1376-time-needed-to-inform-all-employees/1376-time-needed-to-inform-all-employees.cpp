// // just dfs while maintaining max time
// class Solution {
// public:

//     // make note of this wrong dfs
//     // The issue is that the recursion should return the maximum time from a node to any employee in its subtree, 
//     //  rather than trying to maintain a single time variable passed down the recursion.

//     // int dfs(vector<vector<int>>& adj,int u,vector<int>& informTime,int time){
//     //     time=max(time,time+informTime[u]);

//     //     for(int v:adj[u]){
//     //         dfs(adj,v,informTime,time);
//     //     }

//     //     return time;
//     // }

//     void dfs(vector<vector<int>>& adj,int u,vector<int>& informTime,int currTime,int& maxTime){
//         maxTime=max(maxTime,currTime);

//         for(int v:adj[u]){
//             dfs(adj,v,informTime,currTime+informTime[u],maxTime);
//         }

//     }

//     int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
//         // int time=0;

//         vector<vector<int>> adj(n);      // need to decplare adj size since we're doing adj[manager[i]].push_back
//                                          // (i), ow gives out of bounds 

//         int m=manager.size();
//         for(int i=0;i<m;i++){
//             if(i==headID) continue;   // since if headID then manager[headID]=-1, gives seg-fault
//             adj[manager[i]].push_back(i);
//         }

//         int maxTime=0;
//         dfs(adj,headID,informTime,0,maxTime);    // should pass maxTime, can't pass 0, since passing by ref 
//         return maxTime;

        
//     }
// };

class Solution {
public:
    void bfs(vector<vector<int>>& adj,int u,vector<int>& informTime,int currTime,int& maxTime,queue<pair<int,int>> q){
        
        while(!q.empty()) {
            
            auto temp = q.front();
            int curr_emp  = temp.first;
            int curr_time = temp.second;
            
            maxTime = max(maxTime, curr_time);
            
            q.pop();
            
            for(int &v : adj[curr_emp]) {
                q.push({v, curr_time + informTime[curr_emp]}); //Time at which v recieves the information
            }
            
        }

    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // int time=0;

        vector<vector<int>> adj(n);      // need to declare adj size since we're doing adj[manager[i]].push_back
                                         // (i), ow gives out of bounds 

        int m=manager.size();
        for(int i=0;i<m;i++){
            if(i==headID) continue;   // since if headID then manager[headID]=-1, gives seg-fault
            adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        q.push({headID,0});       // because apart from employee id we also need tot time until now and we need 
                                  // to store it in q becuase unlike dfs recursion, we cannot have it stored in a 
                                  // call          
        int maxTime=0;
        bfs(adj,headID,informTime,0,maxTime,q);    // should pass maxTime, can't pass 0, since passing by ref 
        return maxTime;

    }
};