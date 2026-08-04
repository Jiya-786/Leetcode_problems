// brute force
// checking all rotations
// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if(s.length()!=goal.length()) return false;

//         int n=s.length();
//         for(int i=0;i<n;i++){
//             string rotated=s.substr(i)+s.substr(0,i);
//             if(rotated==goal) return true;
//         }
//         return false;
//     }
// };

// concatenate and search
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;

        string doubled=s+s;
        return doubled.find(goal)!=string::npos;
    }
};