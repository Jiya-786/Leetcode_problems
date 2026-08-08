// For a given input, the unordered_map can have anywhere from 1 to 52 entries, depending on which characters appear. But its maximum size is always bounded by 52, regardless of how large the input string becomes. Therefore, the auxiliary space is O(1).

// on time
// o1 space

// even if we have more than one character appearing only once, lets say we have a single a and a single b, we can only choose to add one of them in the middle of the string, ow it does not remain a palindrome.
// class Solution {
// public:
//     int longestPalindrome(string s) {
//         unordered_map<char, int> freq;

//         // Count frequency
//         for (char c : s) {
//             freq[c]++;
//         }

//         int length = 0;
//         bool hasOdd = false;

//         // Check every character's frequency              
//         for (auto& pair : freq){
//             int count = pair.second;

//             length += (count / 2) * 2;

//             if (count % 2 != 0) {
//                 hasOdd = true;
//             }
//         }

//         if (hasOdd) {
//             length++;
//         }

//         return length;
//     }
// };

// one pass soln
// using set
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> oddChars;
        int ans=0;

        for(char c:s){
            if(oddChars.count(c)){
                ans+=2;
                oddChars.erase(c);
            }else{
                oddChars.insert(c);
            }
        }
        if(!oddChars.empty()) ans+=1;

        return ans;
    }
};