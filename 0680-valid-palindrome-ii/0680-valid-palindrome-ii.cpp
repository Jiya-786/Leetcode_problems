// brute force
// gives TLE
// time on2 space on
// class Solution {
// public:
//     bool validPalindrome(string s) {
//         int n=s.length();
//         if(isPalindrome(s)){
//             return true;
//         }
//         for(int i=0;i<n;i++){
//             string s_new=s.substr(0,i)+s.substr(i+1);

//             if(isPalindrome(s_new)) return true;
//         }
//         return false;
//     }
// private:
//     bool isPalindrome(string s_new){
//         string reversed=s_new;
//         reverse(reversed.begin(),reversed.end());

//         return s_new==reversed;
//     }
// };

// optimal 2-pointer soln
class Solution {
public:
    bool validPalindrome(string s) {
        int n=s.length();
        int left=0;
        int right=n-1;

        while(left<right){
            if(s[left]==s[right]){
                left++; right--;
            }
            else{
                return (isPalindrome(s,left+1,right)||isPalindrome(s,left,right-1));
            }
        }
        return true;
    }
private:
    bool isPalindrome(string s,int left,int right){
        while(left<right){
            if(s[left]!=s[right]) return false;

            left++; right--; 
        }
        return true;
    }
};