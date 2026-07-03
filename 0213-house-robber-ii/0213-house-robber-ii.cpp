// bottom-up approach
//we will divide this qs into 2 subproblems to convert it to 2 house robber 1 problems
// checck notes for better understnading

// always define state in bottom up approach
// t[i] represents max value until ith house

// now make this constant space
// just like in house robber 1
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int> t(n+1,0);

        if(n==1) return nums[0];

        int prevPrev=0; int prev=0;
        // case-1 taking house-1 implies we can not take last house, implies only houses until n-1 should be under consideration
        // note index of t runs +1 than nums
        for(int i=1;i<=n-1;i++){
            int skip=prev;
            int steal=nums[i-1]+prevPrev;

            int temp=max(skip,steal);
            prevPrev=prev;
            prev=temp;
        }
        int res1=prev;

        // t.clear();
        prev=0;
        prevPrev=0;
        // case-2 not taking house1, implies we can take house2....last house(nth house)
        // note index of t runs +1 than nums
        for(int i=2;i<=n;i++){
            int skip=prev;
            int steal=nums[i-1]+prevPrev;

            int temp=max(skip,steal);
            prevPrev=prev;
            prev=temp;
        }
        int res2=prev;

        return max(res1,res2);

    }
};