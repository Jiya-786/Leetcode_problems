// bottom-up approach
//we will divide this qs into 2 subproblems to convert it to 2 house robber 1 problems
// checck notes for better understnading

// always define state in bottom up approach
// t[i] represents max value until ith house
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> t(n+1,0);

        if(n==1) return nums[0];

        t[0]=0;
        // case-1 taking house-1 implies we can not take last house, implies only houses until n-1 should be under consideration
        // note index of t runs +1 than nums
        for(int i=1;i<=n-1;i++){
            int skip=t[i-1];
            int steal=nums[i-1]+((i-2)<=0 ? 0 : t[i-2] );

            t[i]=max(skip,steal);
        }
        int res1=t[n-1];

        t.clear();
        t[0]=0;
        t[1]=0;
        // case-2 not taking house1, implies we can take house2....last house(nth house)
        // note index of t runs +1 than nums
        for(int i=2;i<=n;i++){
            int skip=t[i-1];
            int steal=nums[i-1]+((i-2)<=0 ? 0 : t[i-2] );

            t[i]=max(skip,steal);
        }
        int res2=t[n];

        return max(res1,res2);

    }
};