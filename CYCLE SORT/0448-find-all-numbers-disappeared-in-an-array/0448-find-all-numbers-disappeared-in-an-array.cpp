// USING CYCLE SORT
// this is a good problem to understnad duplicates in cyclesort
// the duplicates remain stuck in the worn position and we log each mismatch into an array
// unlike previous problems where we were only looking for a single no, here we are dealing   with    multiple answers, which we will log into an array
// thats the only difference

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
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
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};