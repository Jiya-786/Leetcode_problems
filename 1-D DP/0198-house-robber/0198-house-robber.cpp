// bottom-up approach

// first thing always in this approach is defining the state
// let t[i]= amount of money stolen until i'th house
// so t[i] = max(stolen,skip)
// t[i] will always me max psbl amt until ith house
// When you decide to rob house i, you don't care whether house i-1 was skipped in some particular solution. You only care about the best legal profit that definitely doesn't involve house i-1, and that's exactly what t[i-2] guarantees.

// space-optimized bottom-up

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> t(n+1,0);

        if(n==1) return nums[0];

        int prevPrev=0;
        int prev=nums[0];

        for(int i=2;i<=n;i++){
            int skip=prev;
            int steal=nums[i-1]+prevPrev;

            t[i]=max(skip,steal);

            int temp=max(skip,steal);

            prevPrev=prev;
            prev=temp;
        }
        return prev;

    }

};