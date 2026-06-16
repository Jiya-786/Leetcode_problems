// BRUTE FORCE
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int maxLen=0;
//         int n=s.size();

//         for(int i=0;i<n;i++){
//             unordered_set<char> seen;
//             for(int j=i;j<n;j++){
//                 if(seen.count(s[j])) break;
//                 seen.insert(s[j]);
//                 maxLen=max(maxLen,j-i+1);
//             }
//         }
//         return maxLen;
//     }
// };

// we will use sliding window technique

// we move the right pointer to add a new character to the window

// if the new character is already in the window, move left pointer form=ward until the duplicate is gone

// at each step caluclate window size using right-left+1 and keep track of the maximum
// we use an array of size 256 to store the last seen index of each character. this allows left pointer to jump instead of sliding by one in case of sliding window max
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();

        unordered_set<char>window;
        int left=0;
        int maxLen=0;

        for(int i=0;i<n;i++){
            while(window.count(s[i])){
                window.erase(s[left]);
                left++;
            }
            window.insert(s[i]);
            maxLen=max(maxLen,i-left+1);
        }
        return maxLen;
    }
};