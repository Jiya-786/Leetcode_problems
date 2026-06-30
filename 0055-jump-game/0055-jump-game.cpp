// greedy
// problem says max jump length ie we also need to chekc shorter jump
// always keep track of the farthest we can reach, discard the rest- GREEDY
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxPos=0;      
        int pos=0;
        for(int i= 0;i<n;i++){
            if(i>maxPos) return false;       // becuase maxPos gives the max position we can reach at that given time, we can never go beyond maxPos, hence returning false
            maxPos=max(maxPos,nums[i]+i);
            if(maxPos>=n-1) return true;
        }
        return false;
    }
};
