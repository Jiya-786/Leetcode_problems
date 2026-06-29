class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxPos=0;
        int pos=0;
        for(int i= 0;i<n;i++){
            if(i>maxPos) return false;
            maxPos=max(maxPos,nums[i]+i);
            if(maxPos>=n-1) return true;
        }
        return false;
    }
};