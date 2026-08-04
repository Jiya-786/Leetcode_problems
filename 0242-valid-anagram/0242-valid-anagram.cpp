// sorting-
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.size() != t.size()) return false;

//         // Sort both strings and compare
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());

//         return s == t;
//     }
// };

// most optimal
// on time
// o1 space  
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

