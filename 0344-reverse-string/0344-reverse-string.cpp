// bute force
//using extra array
// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         vector<char> ans;
//         int n=s.size();
        
//         for(int i=n-1;i>=0;i--){
//             ans.push_back(s[i]);
//         }

//         for(int i=0;i<n;i++){
//             s[i]=ans[i];
//         }
//     }
// };

// in-place using two pointers
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int left=0;
        int right=n-1;
        
        while(left<right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};

