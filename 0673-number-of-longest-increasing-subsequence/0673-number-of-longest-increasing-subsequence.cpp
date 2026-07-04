class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n, 1); // LIS length ending at i
        vector<int> cnt(n, 1);    // Number of LIS ending at i
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (length[j] + 1 > length[i]) {
                        // Found a longer subsequence ending at i
                        length[i] = length[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (length[j] + 1 == length[i]) {
                        // Found another way to reach the same length
                        cnt[i] += cnt[j];
                    }
                }
            }
            maxLen = max(maxLen, length[i]);
        }

        // Sum counts for all positions achieving max length
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (length[i] == maxLen) {
                result += cnt[i];
            }
        }
        return result;
    }
};