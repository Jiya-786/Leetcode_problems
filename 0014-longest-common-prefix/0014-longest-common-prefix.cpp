// the qs is ambiguous, but we are req to find common prefix bw all strings not the most occuring common prefic in some subset of input.
// vertical scanning
// brute force
// check every possible prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        for(int i=0;i<strs[0].length();i++){
            char c=strs[0][i];

            for(int j=1;j<strs.size();j++){
                if(i==strs[j].length()||c!=strs[j][i]){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};