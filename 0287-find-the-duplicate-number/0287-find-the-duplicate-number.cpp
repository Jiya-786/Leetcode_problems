// USING CYCLE SORT
// similar to set-mismatch logic
// qhenever we find a mismatch, i+1 will be the missing number and nums[i] will be the duplicate
// becuase duplicates in cycle sort get stuck in the worng postion
// and this qs guarantees only 1 duplicate, hence it is easier to solve
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
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
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return nums[i];
            }
        }
        return n+1;
    }
};