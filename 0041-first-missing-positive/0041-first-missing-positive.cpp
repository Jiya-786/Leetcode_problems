// using sorting
// time o(nlogn)
// space o(1)
// this time-space tradeoff is ipp to the one in hashset, none are optimal but it reveals the problem beautifully

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int expected=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0 || i>0 && nums[i]==nums[i-1]){
                continue;
            }
            else{
                if(nums[i]==expected){
                    expected++;
                }
                else{
                    break;
                }
            }
        }
        return expected;
    }
};