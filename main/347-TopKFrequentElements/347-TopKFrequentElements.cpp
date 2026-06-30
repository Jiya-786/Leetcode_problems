// Last updated: 30/06/2026, 19:33:21
// // // #include <vector>
// // // #include <queue>
// // // #include <unordered_map>
// // // using namespace std;

// // // class Solution {
// // // public:
// // //     vector<int> topKFrequent(vector<int>& nums, int k){
// // //         unordered_map<int,int> freq;

// // //         for(int x:nums){
// // //             freq[x]++;
// // //         }

// // //         // priority queue syntax-
// // //         // priority_queue <TYPE,CONTAINER,COMPARATOR>
// // //         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

// // //         for(auto &p:freq){
// // //             // for priority queue we use push not push_back
// // //             // push_back is used for vector

// // //             // A priority queue compares elements based on the first
// // //             // value of the pair by default, so, if we want the heap to order by
// // //             // frequency, the
// // //             // frequency must come first
// // //             pq.push({p.second,p.first});
// // //             // when we write pq.push({p.second,p.first}); we are pushing
// // //             // one object
// // //             // of type pair<int,int> into the heap

// // //             // so now pq looks like (freq,number)

// // //             if(pq.size()>k){
// // //                 pq.pop();
// // //             }
// // //         }

// // //         vector<int> ans;
// // //         while(!pq.empty()){
// // //             ans.push_back(pq.top().second);
// // //             // rember pq looks like (freq,number) and qs asks
// // //             // to return the number
// // //             pq.pop();
// // //         }

// // //         return ans;

// // //     }
// // // };

// // // FREQ-MAP METHOD
// time o(nlogn)
// // class Solution {
// // public:
// //     vector<int> topKFrequent(vector<int>& nums, int k) {
// //         unordered_map<int,int> freq;
// //         int n=nums.size();

// //         for(int i=0;i<n;i++){
// //             freq[nums[i]]++;
// //         }
// //         // now to sort the map by second elt, put all the elts in a vector and sort by freq

// //         vector<pair<int,int>> vec(freq.begin(),freq.end());

// //         sort(vec.begin(),vec.end(),[](auto& a, auto& b){
// //             return a.second>b.second;
// //         });                                                 // for custom ordering in vector pair comparisions we 
// //                                                             // need lamda function, ow it orders by first elt.
// //         vector<int> result;
// //         for(int i=0;i<k;i++){
// //             result.push_back(vec[i].first);
// //         }
// //         return result;
// //     }
// // };

// // PRIORITY-QUEUE METHOD
// time o(nlogk)
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int,int> freq;

//         for(int x:nums){
//             freq[x]++;
//         }

//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//         for(auto& it:freq){
//             pq.push({it.second,it.first});

//             if(pq.size()>k) pq.pop();
//         }

//         vector<int> result;
//         while(!pq.empty()){                            // not for(auto& it:pq)
//             result.push_back(pq.top().second);        // not result.push_back(it.second);
//             pq.pop();      
//         }
//         return result;
//     }
// };

// BUCKET SORT
// time o(n): best of all
// space o(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(int x:nums){
            freq[x]++;
        }

        int n=nums.size();
        vector<vector<int>> buckets(n+1);
        for(auto& it:freq){
            buckets[it.second].push_back(it.first);
        }

        vector<int> result;
        for(int i=n;i>=0 && result.size()<k;i--){
            for(int num:buckets[i]){
                result.push_back(num);
                if(result.size()==k) break;
            }
        }
        return result;
    }
};