// #include <vector>
// #include <queue>
// #include <unordered_map>
// using namespace std;

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k){
//         unordered_map<int,int> freq;

//         for(int x:nums){
//             freq[x]++;
//         }

//         // priority queue syntax-
//         // priority_queue <TYPE,CONTAINER,COMPARATOR>
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

//         for(auto &p:freq){
//             // for priority queue we use push not push_back
//             // push_back is used for vector

//             // A priority queue compares elements based on the first
//             // value of the pair
//             // by default, so, if we want the heap to order by
//             // frequency, the
//             // frequency must come first
//             pq.push({p.second,p.first});
//             // when we write pq.push({p.second,p.first}); we are pushing
//             // one object
//             // of type pair<int,int> into the heap

//             // so now pq looks like (freq,number)

//             if(pq.size()>k){
//                 pq.pop();
//             }
//         }

//         vector<int> ans;
//         while(!pq.empty()){
//             ans.push_back(pq.top().second);
//             // rember pq looks like (freq,number) and qs asks
//             // to return the number
//             pq.pop();
//         }

//         return ans;

//     }
// };

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int n=nums.size();

        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        // now to sort the map by second elt, put all the elts in a vector and sort by freq

        vector<pair<int,int>> vec(freq.begin(),freq.end());

        sort(vec.begin(),vec.end(),[](auto& a, auto& b){
            return a.second>b.second;
        });                                                 // for custom ordering in vector pair comparisions we 
                                                            // need lamda function, ow it orders by first elt.
        vector<int> result;
        for(int i=0;i<k;i++){
            result.push_back(vec[i].first);
        }
        return result;
    }
};