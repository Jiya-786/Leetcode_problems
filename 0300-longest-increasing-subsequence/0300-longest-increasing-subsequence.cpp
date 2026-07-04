// BRUTE FORCE
// plain recursion
// gives TLE
// exponential time complexity
// hence memoize
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         return solve(nums,0,-1);
//     }
// private:
//     int solve(vector<int>& nums,int i,int p_index){
//         if(i>=nums.size()) return 0;

//         int take=0;   // don't forget to define it outisde the if condition
//         if(p_index==-1 || nums[i]>nums[p_index]) take=1+solve(nums,i+1,i);
//         int skip=solve(nums,i+1,p_index);

//         return max(take,skip);
//     }
// };

// memoizing
// this is a 2D-dp because 2 parameters are changing within one recursion call: curr index and prev index
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> t(n+1,vector<int>(n+1,-1));
        return solve(nums,0,-1,t);    // becuase prev index is starting from 0, when filing out th dp grid, fill in 
                                      // using p_index+1
    }
private:
    int solve(vector<int>& nums,int i,int p_index,vector<vector<int>>& t){
        if(i>=nums.size()) return 0;
        
        if(t[i][p_index+1]!=-1) return t[i][p_index+1];

        int take=0;   // don't forget to define it outisde the if condition
        if(p_index==-1 || nums[i]>nums[p_index]) take=1+solve(nums,i+1,i,t);
        int skip=solve(nums,i+1,p_index,t);

        return t[i][p_index+1]=max(take,skip);
    }
};