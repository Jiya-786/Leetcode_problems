// Last updated: 30/06/2026, 19:31:20
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>> pq;

        for(auto &x:points){
            int dist=x[0]*x[0]+x[1]*x[1];
            pq.push({dist,x});

            if(pq.size()>k){
                pq.pop();
            }
        }
        // vector<pair<int,int>> ans;
        // in given qs outline, point is stored as vector<vector<int>>
        // hence we will use the same format for answer and not
        // vector<pair<int,int>> moreover the
        // return type is also mentioned as vector<vector<int>>

        // while(!pq.empty()){
        //     ans.push_back(pq.top())
        // }

        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};