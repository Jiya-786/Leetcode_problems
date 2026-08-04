// brute force
// filter and reverse
// class Solution {
// public:
//     bool isPalindrome(string s) {
//         // cleaning the string
//         string cleaned="";
//         for(char c:s){
//             if(isalnum(c)){
//                 cleaned+=tolower(c);
//             }
//         }

//         // compare with its reverse
//         // int n=cleaned.size();
//         // int left=0; int right=n-1;
//         // bool ans=true;
//         // while(left>right){
//         //     if(cleaned[left]!=cleaned[right]){
//         //         ans=false;
//         //         break;
//         //     }
//         //     else{
//         //         left++; right--;
//         //     }

//         // }
//         // return ans
//         // easiest way-
        
//         string reversed=cleaned;
//         reverse(reversed.begin(),reversed.end());
//         return reversed==cleaned; 
//     }
// };

// o1 space soln
// keep skipping all non alphanumeric characters and compare both sides
class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int left=0;
        int right=n-1;
        
        while(left<right){
            while(left<right && !isalnum(s[left])){
                left++;
            }
            while(left<right && !isalnum(s[right])){
                right--;
            }
            if(tolower(s[left])!=tolower(s[right])){
               return false;
            }
            left++; right--;
        }
        return true;
    }
};