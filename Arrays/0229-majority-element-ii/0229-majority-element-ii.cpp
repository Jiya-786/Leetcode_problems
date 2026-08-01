// m1 direct hash-map method
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         unordered_map<int,int> countMap;
//         int n=nums.size();
//         int threshold=n/3;
//         vector<int> result;

//         for(int num:nums){
//             countMap[num]++;
//         }
//         for(auto& it:countMap){
//             if(it.second>threshold) result.push_back(it.first);
//         }
//         return result;
//     }
// };

// scan over the sorted array, measuring each run's length and comparing it against the threshold,
// finds every majority element. This trades the O(n) space of a hash map for the O(n log n) time 
// of sorting, and it modifies the input.
// gives TLE though
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> result;
//         sort(nums.begin(),nums.end());

//         int i=1;
//         int prev=nums[0];
//         while(i<n){
//             int count=0;
//             while(i<n && nums[i]==prev){
//                 count++;
//                 i++;
//             }
//             if(count>n/3){
//                 result.push_back(nums[i]);
//             }
//         }
//         return result;
//     }
// };

// boyer-moore voting algo
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cand1=0; int cand2=0;
        int count1=0; int count2=0;

        for(int num:nums){
            if(num==cand1) count1++;
            else if(num==cand2) count2++;
            else if(count1==0){
                cand1=num;
                count1=1;
            }
            else if(count2==0){
                cand2=num;
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        // WHY verification is req here-

        // For n/2, the majority element has more votes than everyone else combined, so it cannot lose.
        // For n/3, it only has more votes than one-third, so it can lose during cancellation; therefore we must recount.

        count1=0; count2=0;
        for(int num:nums){
            if(num==cand1) count1++;
            else if(num==cand2) count2++;
        }

        vector<int> result;
        if(count1>n/3) result.push_back(cand1);
        if(count2>n/3) result.push_back(cand2);
        return result;
    }
};