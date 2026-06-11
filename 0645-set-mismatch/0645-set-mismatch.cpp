// USING CYCLE SORT
// notice in the find-all-nors-disappeared qs we noticed that duplicate entries stay stuck at a random place
// we use that fact here
// here it is guaranteed we will only have 1 duplicate entry
// so the moment we get a mismatch, we will know which entry is missing and the number at that mismatch position will be a duplicate, hence we will have both our req nors
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int i=0;

        while(i<n){
            if(nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
            else{
                i++;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                ans.push_back(nums[i]);
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};