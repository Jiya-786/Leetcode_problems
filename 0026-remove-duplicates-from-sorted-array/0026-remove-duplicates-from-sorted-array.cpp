// using hash-set
// this is not inplace
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> seen(nums.begin(),nums.end());
        vector<int> unique(seen.begin(),seen.end());
        sort(unique.begin(),unique.end());
        int k=unique.size();

        for(int i=0;i<k;i++){
            nums[i]=unique[i];
        }

        return k;

    }
};