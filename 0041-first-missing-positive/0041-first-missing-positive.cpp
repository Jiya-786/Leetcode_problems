class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        int counter=1;
        while(true){
            if(mp[counter]==0){
                return counter;
            }
            else counter++;
        }
        return -1;
    }
};