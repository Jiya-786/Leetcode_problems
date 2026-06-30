// Last updated: 30/06/2026, 19:32:39
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        vector<int> s1Freq(26, 0), windowFreq(26, 0);

        // Build frequency arrays for s1 and the first window
        for (int i = 0; i < n; i++) {
            s1Freq[s1[i] - 'a']++;
            windowFreq[s2[i] - 'a']++;
        }

        // Count initial matches
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1Freq[i] == windowFreq[i]) matches++;
        }

        for (int i = n; i < m; i++) {
            if (matches == 26) return true;

            // Add the character entering the window
            int addIdx = s2[i] - 'a';
            windowFreq[addIdx]++;
            if (windowFreq[addIdx] == s1Freq[addIdx]) matches++;
            else if (windowFreq[addIdx] == s1Freq[addIdx] + 1) matches--;

            // Remove the character leaving the window
            int remIdx = s2[i - n] - 'a';
            windowFreq[remIdx]--;
            if (windowFreq[remIdx] == s1Freq[remIdx]) matches++;
            else if (windowFreq[remIdx] == s1Freq[remIdx] - 1) matches--;
        }

        return matches == 26;
    }
};