// bottom-up approach

// first thing always in this approach is defining the state
// let t[i]= amount of money stolen until i'th house
// so t[i] = max(stolen,skip)
// t[i] will always me max psbl amt until ith house
// When you decide to rob house i, you don't care whether house i-1 was skipped in some particular solution. You only care about the best legal profit that definitely doesn't involve house i-1, and that's exactly what t[i-2] guarantees.

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> t(n+1,0);

        if(n==1) return nums[0];

        t[0]=0;
        t[1]=nums[0];

        for(int i=2;i<=n;i++){
            int skip=t[i-1];
            int steal=nums[i-1]+t[i-2];

            t[i]=max(skip,steal);
        }
        return t[n];

    }

};