// Last updated: 30/06/2026, 19:33:15
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> map;
        for(char c:s){
            map[c]++;
        }
        for(int i=0;i<s.length();i++){
            if(map[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     int firstUniqChar(string s) {
//         queue<int> q;
//         for(inti=0;i<s.length();i++){
//             if(s[q.front()]==s[i]){
//                 while(!q.empty() && s[q.front()]==s[i]){
//                     q.pop();
//                 }
//             }
//             else{
//                 q.push(i);
//             }
//         }
//         if(q.empty()) return -1;
//         else return q.front();
//     }
// };