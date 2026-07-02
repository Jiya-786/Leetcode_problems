// DP solution
// bottom-up approach+space-optimized
class Solution {
public:
    int climbStairs(int n) {
        // vector<int> t(n+1,-1);
        if(n<=2) return n;
        
        int a=1; int b=2;
        int c=0;

        for(int i=1;i<=n-2;i++){
             c=a+b;
             a=b;
             b=c;
        }
        return c;
    }
};