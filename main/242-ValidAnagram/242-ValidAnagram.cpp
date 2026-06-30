// Last updated: 30/06/2026, 19:33:59
// most optimal on time o1 space solution 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

unordered_map<char,int> count;
for(int i = 0; i < s.length(); i++) {
    count[s[i]]++;
    count[t[i]]--;
}

for(auto& p : count) {
    if(p.second != 0) return false;
}
return true;
    }
};

// the solution i tried- O(n) time O(n) space
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         unordered_map<char,int> s1,s2;

//         int n=s.length();
//         int m=t.length();

//         for(int i=0;i<n || i<m;i++){
//             // s1[s[i]]++;
//             // s2[t[i]]++;
//             if(i<n) s1[s[i]]++;
//             if(i<m) s2[t[i]]++;
//         }

//         return s1==s2;
//     }
// };