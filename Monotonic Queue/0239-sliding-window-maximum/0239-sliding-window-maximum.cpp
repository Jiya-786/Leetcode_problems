// // // BRUTE FORCE
// // class Solution {
// // public:
// //     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
// //         int n=nums.size();
// //         vector<int> ans;

// //         for(int i=0;i<=n-k;i++){
// //             int req=nums[i];
// //             for(int j=i+1;j<i+k;j++){
// //                 req=max(req,nums[j]);
// //             }
// //             ans.push_back(req);
// //         }
// //         return ans;
// //     }   
// // };

// // PRIORITY QUEUE METHOD
// // time o(nlogn)
// // space o(n)
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n=nums.size();
//         vector<int> ans;
//         priority_queue<pair<int,int>> pq;

//         for(int i=0;i<k;i++){
//             pq.push({nums[i],i});
//         }
//         ans.push_back(pq.top().first);

//         for(int i=k;i<n;i++){
//             pq.push({nums[i],i});
//             // removing elts outside the window
//             while(pq.top().second<=i-k){
//                 pq.pop();
//             }
//             ans.push_back(pq.top().first);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        vector<int> ans;

        for(int i=0;i<n;i++){
            // remove indices outside the window
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

            // remove smaller elts from the back
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};