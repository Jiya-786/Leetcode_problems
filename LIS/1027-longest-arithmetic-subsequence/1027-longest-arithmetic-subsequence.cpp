//Approach-1 : Recursion + Memoization (TLE)
// class Solution {
// public:
//     int n;
//     int t[1001][1003];
    
//     int solve(vector<int>& nums, int i, int diff) {
        
//         if(i < 0)
//             return 0;
        
//         if(t[i][diff+501] != -1)      // +501 to take care of -ve common diff
//             return t[i][diff+501];
        
//         int ans = 0;
        
//         for(int k = i-1; k >= 0; k--) {            // we either need to check front or back elts to see which toehr elts satisfy the common difference, not front and back both since say we check all back wars elts of i, then if the confusion is wee will miss out on the front elts of i, it won't happen since we will check for all i from start to end, so if there is such a seq that will micc out on fwd elts at some i, we will definitely cover them in further iterations. 
                                                  
            
//             if(nums[i] - nums[k] == diff)
//                 ans = max(ans, 1 + solve(nums, k, diff));
            
//         }
        
//         return t[i][diff+501] = ans;
//     }
    
//     int longestArithSeqLength(vector<int>& nums) {
//         n = nums.size();
//         if(n <= 2)
//             return n;
        
//         memset(t, -1, sizeof(t));
        
        
//         int result = 0;
        
//         for(int i = 0; i<n; i++) {
//             for(int j = i+1; j < n; j++) {
                
//                 result = max(result, 2 + solve(nums, i, nums[j] - nums[i]));
                
//             }
//         }
        
//         return result;
//     }
// };


//Approach-2 (Just solve it like Longest Increasing Subsequence)
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        
        if(n <= 2)
            return n;
        
        vector<vector<int>> t(n, vector<int>(1001,0));      // usually we req 1-D dp array even if memoization reqs 2-d arr, beciase this problem we not only need to maintain count in dp and update current count, but also need to check if the common diff at that state is matching the reqs, hence we need a 2-D dp array
        //t[i][j] = Max AP length till ith index (0 to i) having common difference j

        int result = 0;
        
        for (int i = 1; i<n; i++) {
            
            for (int j=0; j<i; j++) {
                
                int diff    = nums[i] - nums[j] + 500; //to avoid negative diff
                
                t[i][diff] = t[j][diff] > 0 ? t[j][diff] + 1 : 2;
                
                result      = max(result, t[i][diff]);
            }
        }

        return result;
    }
};