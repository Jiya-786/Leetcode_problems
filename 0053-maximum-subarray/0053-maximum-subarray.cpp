// // Brute Force
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int maxSum = nums[0];

//         for (int i = 0; i < nums.size(); i++) {
//             int currentSum = 0;
//             for (int j = i; j < nums.size(); j++) {
//                 currentSum += nums[j];
//                 maxSum = max(maxSum, currentSum);
//             }
//         }

//         return maxSum;
//     }
// };

// KADANES ALGORITHM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int currentSum=nums[0];
        int maxSum=nums[0];

        for(int i=1;i<n;i++){
            currentSum=max(nums[i],currentSum+nums[i]);
            maxSum=max(maxSum,currentSum);
        }
        return maxSum;
    }
};