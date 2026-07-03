// classic BRUTE FORCE
// time o(n*n^n-1): exponential
// gives TLE for big n
// notice repeating sub-problems
// hence memoize
// class Solution {
// public:
//     int integerBreak(int n) {
//         if(n==1) return 1;

//         int ans=0;
//         for(int i=1;i<=n-1;i++){
//             ans=max(ans,i*max(n-i,integerBreak(n-i)));
//         }
//         return ans;
//     }
// };

// memoized soln
// time complexity ~o(n^2)
class Solution {
public:
    vector<int> t=vector<int>(59,-1);    // or we can also resize inside the function on every call

    int integerBreak(int n) {
        if(n==1) return 1;

        if(t[n]!=-1) return t[n];

        int ans=0;
        for(int i=1;i<=n-1;i++){
            ans=max(ans,i*max(n-i,integerBreak(n-i)));
        }
        return t[n]=ans;
    }
};
