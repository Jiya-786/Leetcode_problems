// m1 direct hash-map method
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> countMap;
        int n=nums.size();
        int threshold=n/3;
        vector<int> result;

        for(int num:nums){
            countMap[num]++;
        }
        for(auto& it:countMap){
            if(it.second>threshold) result.push_back(it.first);
        }
        return result;
    }
};