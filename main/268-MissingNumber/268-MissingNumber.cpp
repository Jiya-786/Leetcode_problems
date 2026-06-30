// Last updated: 30/06/2026, 19:33:55
// USING CYCLE SORT
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        
        int i=0;

        while(i<n){
            if(nums[i]<n && nums[i]!=nums[nums[i]]){   // if no is in range ie <n and does not
                                                       // have a duplicate, and still not in
                                                       // correct position, bring it into
                                                       // correct position
                swap(nums[i],nums[nums[i]]);
            }
            else{
                i++;  // if no. not in range, move on to next number
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                return i;
            }
        }
        return n;
    }
};