// Approach 1: Two Pointers

// For a single query, this is already optimal. But the follow-up asks what happens when we have billions of queries against the same t. Every query re-scans t from scratch. Can we preprocess t once so each query skips the linear scan?

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;

        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++;j++;
            }
            else{
                j++;
            }
        }
        return i==s.size();
    }
};