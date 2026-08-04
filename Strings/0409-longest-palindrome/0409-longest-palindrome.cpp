class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;

        // Count frequency
        for (char c : s) {
            freq[c]++;
        }

        int length = 0;
        bool hasOdd = false;

        // Check every character's frequency
        for (auto& pair : freq) {
            int count = pair.second;

            length += (count / 2) * 2;

            if (count % 2 != 0) {
                hasOdd = true;
            }
        }

        if (hasOdd) {
            length++;
        }

        return length;
    }
};