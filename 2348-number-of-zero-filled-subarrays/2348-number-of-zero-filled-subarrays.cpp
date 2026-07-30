class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        int consecutiveZeros = 0;

        for (int num : nums) {
            if (num == 0) {
                consecutiveZeros++;
            } else {
                consecutiveZeros = 0;
            }
            // Each new zero in a run of length k adds k new subarrays
            count += consecutiveZeros;
        }

        return count;
    }
};