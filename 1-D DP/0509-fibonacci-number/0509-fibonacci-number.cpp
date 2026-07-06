// DP bottom-up approach
// constant space soln
// space optimized becaise we will alwys need just the last 2 numbers
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int a=0; int b=1;
        int c=0;

        for(int i=0;i<n-1;i++){
            c=a+b;
            a=b; b=c;
        }
        return c;
    }
};