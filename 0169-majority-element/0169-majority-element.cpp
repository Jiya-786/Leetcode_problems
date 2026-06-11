// just sort and take the elt at n/2 position 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=(nums.size())/2;
        return nums[n];

    }
};