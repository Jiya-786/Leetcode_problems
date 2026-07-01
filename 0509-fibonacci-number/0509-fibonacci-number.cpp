// DP bottom-up approach
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        vector<int> t(n+1,-1);

        t[0]=0; t[1]=1;
        for(int i=2;i<=n;i++){
            t[i]=t[i-1]+t[i-2];
        }

        return t[n];
        
    }
};