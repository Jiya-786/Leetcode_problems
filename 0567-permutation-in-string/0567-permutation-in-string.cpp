// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         // Sort to get the lexicographically smallest permutation
//         sort(s1.begin(), s1.end());

//         // Try every permutation of s1
//         do {
//             if (s2.find(s1) != string::npos) {
//                 return true;
//             }
//         } while (next_permutation(s1.begin(), s1.end()));

//         return false;
//     }
// };

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

        if (s1Freq == windowFreq) return true;

        // Slide the window across s2
        for (int i = n; i < m; i++) {
            windowFreq[s2[i] - 'a']++;           // Add new char
            windowFreq[s2[i - n] - 'a']--;       // Remove old char
            if (s1Freq == windowFreq) return true;
        }

        return false;
    }
};