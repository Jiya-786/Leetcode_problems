// split and find last word
// on time
// on space
// since the split allocates a list of all words, which in the worst case holds every character.
// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         istringstream stream(s);
//         string word,last;
//         while(stream>>word){
//             last=word;
//         }
//         return last.length();
//     }
// };

// scan from end
// optimal
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();

        int i=n-1;
        while(i>=0 && s[i]==' ') i--;

        int ans=0;
        while (i>=0 && s[i]!=' '){
            ans++;
            i--;
        }
        return ans;
    }
};