// // BRUTE FORCE
// // basic recursion
// //gives TLE
// // time o(2^n): exponential
// // space o(n): due to call stack
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         return solve(nums,0);
//     }
// private:
//     int solve(vector<int>& nums, int i){
//         int n=nums.size();
//         if(i>=n) return 0;

//         int skip=solve(nums,i+1);
//         int steal=nums[i]+solve(nums,i+2);

//         return max(skip,steal);
//     }
// };

// BRUTE FORCE
// basic recursion
//gives TLE
// time o(2^n): exponential
// space o(n): due to call stack

// hence memoize
// time o(n)
// space o(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> t(n+1,-1);
        return solve(nums,0,t);
    }
private:
    int solve(vector<int>& nums, int i,vector<int>& t){
        int n=nums.size();
        if(i>=n) return 0;

        if(t[i]!=-1) return t[i];

        int skip=solve(nums,i+1,t);
        int steal=nums[i]+solve(nums,i+2,t);

        return t[i]=max(skip,steal);
    }
};