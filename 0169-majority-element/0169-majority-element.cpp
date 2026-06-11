// making an unordered map
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=(nums.size())/2;
        for(int a:nums){
            mp[a]++;
        }
        // int ans;
        for(int b:nums){
            if(mp[b]>n){
                return b;
            }
        }
        return -1;
    }
};