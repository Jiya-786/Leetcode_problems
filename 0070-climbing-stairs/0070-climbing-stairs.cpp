// DP solution
// recursion+memoization
// time o(n) cuz Each subproblem from 1 to n is computed exactly once, doing O(1) work per subproblem.
// space o(n)
class Solution {
public:

    int solve(int n,vector<int>& t){
        if(t[n]!=-1) return t[n];

        return t[n]=solve(n-1,t)+solve(n-2,t);
    }

    int climbStairs(int n) {
        vector<int> t(n+1,-1);
        t[0]=1;
        // t[1]=1;
        // t[2]=2;
        // to prevent out of bounds eg when n=1, vector size=2 , indices 0,1 only will be available, so write:
        if(n>=1) t[1]=1;
        if(n>=2) t[2]=2;

        return solve(n,t);
    }
};