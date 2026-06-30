// Last updated: 30/06/2026, 19:34:22
// unordered map gives o(1) time complexity 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int> result;
        int n=nums.size();

        for(int x:nums){
            freq[x]=freq[x]+1;
        }
        for(auto it:freq){
            if(it.second>(n/3)){
                result.push_back(it.first);
            }
        }
        return result;
    }
};