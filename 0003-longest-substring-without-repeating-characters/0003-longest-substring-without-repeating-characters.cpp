// Instead of a set that only tells us whether a character is in the window, we use a hash map that stores the most recent index of each character. When we encounter a duplicate, we can jump the left pointer directly past the previous occurrence, no need to slide one step at a time.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> lastIndex;
        int left=0;
        int maxLen=0;

        for(int i=0;i<n;i++){
            char c=s[i];
            if(lastIndex.count(c) && lastIndex[c]>=left){
                left=lastIndex[c]+1;
            }
            lastIndex[c]=i;
            maxLen=max(maxLen,i-left+1);
        }
        return maxLen;
    }
};