// the qs is ambiguous, but we are req to find common prefix bw all strings not the most occuring common prefic in some subset of input.
// vertical scanning
// brute force
// check every possible prefix
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         if(strs.empty()) return "";

//         for(int i=0;i<strs[0].length();i++){
//             char c=strs[0][i];

//             for(int j=1;j<strs.size();j++){
//                 if(i==strs[j].length()||c!=strs[j][i]){
//                     return strs[0].substr(0,i);
//                 }
//             }
//         }
//         return strs[0];
//     }
// };

// sort lexicographically
// like in a dictionary
// the first and last string common prefix after sorting
// that will be the longest common prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        sort(strs.begin(),strs.end());

        string first=strs[0];
        string last=strs[strs.size()-1];

        int i=0;
        while(i<first.length() && i<last.length() && first[i]==last[i]){
            i++;
        }
        return strs[0].substr(0,i);
    }
};