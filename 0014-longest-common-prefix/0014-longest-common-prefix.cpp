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
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         if (strs.empty()) return "";

//         sort(strs.begin(),strs.end());

//         string first=strs[0];
//         string last=strs[strs.size()-1];

//         int i=0;
//         while(i<first.length() && i<last.length() && first[i]==last[i]){
//             i++;
//         }
//         return strs[0].substr(0,i);
//     }
// };

// divide and conquer
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int n=strs.size();
        return findLCP(strs,0,n-1);
    }
private:
    string findLCP(vector<string>& strs,int left,int right){
        if(left==right) return strs[left];

        int mid=left+(right-left)/2;

        string lcpLeft=findLCP(strs,left,mid);
        string lcpRight=findLCP(strs,mid+1,right);

        return commonPrefix(lcpLeft,lcpRight);
    }

    string commonPrefix(string& s1,string& s2){
        int minLen=min(s1.length(),s2.length());
        for(int i=0;i<minLen;i++){
            if(s1[i]!=s2[i]){
                return s1.substr(0,i);
            }
        }
        return s1.substr(0,minLen);
    }
};