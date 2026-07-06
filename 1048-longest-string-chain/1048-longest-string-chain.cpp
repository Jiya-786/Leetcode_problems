// // DP top-down approach
// // // simple recursion without memoization
// // // time o(2^n): exponential
// // // exact same as LIS- take or not take
// // // except here comparision condition is isSubsequence() two pointer function rather than no. at prev index
// // class Solution {
// // public:

// //     bool isSubseq(string& a,string& b){
// //         int n=a.length(); int m=b.length();
// //         if(m-n!=1) return false;

// //         int i=0; int j=0;
// //         while(i<n && j<m){
// //             if(a[i]==b[j]) i++;
// //             j++;
// //         }
// //         return i==n;
// //     }

// //     int solve(vector<string>& words, int i, int p_index){
// //         if(i>=words.size()) return 0;

// //         int take=0; int skip=0;
// //         if(p_index==-1 || isSubseq(words[p_index],words[i])){    // make sure youre passign the correct order of 
// //                                                                  // strings into is Subseq
// //             take=1+solve(words,i+1,i);
// //         }
// //         skip=solve(words,i+1,p_index);
// //         return max(take,skip);
// //     }

// //     int longestStrChain(vector<string>& words) {
// //         sort(words.begin(),words.end(),[](string a, string b){return a.length()<b.length();});
// //         return solve(words,0,-1);
// //     }

// // };

// // memoizing
// class Solution {
// public:
//     vector<vector<int>> t;      // declare here initialize inside function or 
//                                 // use = initialization or brace initialization
//     bool isSubseq(string& a,string& b){
//         int n=a.length(); int m=b.length();
//         if(m-n!=1) return false;

//         int i=0; int j=0;
//         while(i<n && j<m){
//             if(a[i]==b[j]) i++;
//             j++;
//         }
//         return i==n;
//     }

//     int solve(vector<string>& words, int i, int p_index){
//         if(i>=words.size()) return 0;

//         if(t[i][p_index+1]!=-1) return t[i][p_index+1];

//         int take=0; int skip=0;
//         if(p_index==-1 || isSubseq(words[p_index],words[i])){    // make sure youre passign the correct order of 
//                                                                  // strings into is Subseq
//             take=1+solve(words,i+1,i);
//         }
//         skip=solve(words,i+1,p_index);
//         return t[i][p_index+1]=max(take,skip);
//     }

//     int longestStrChain(vector<string>& words) {
//         // don't forget to sort
//         sort(words.begin(),words.end(),[](string a, string b){return a.length()<b.length();}); 
//         t.assign(1001,vector<int>(1001,-1));
//         return solve(words,0,-1);
//     }

// };

// bottom-up approach
// time o(n^2)
// define state : dp[i] tells max length of LIS until ith index
class Solution {
public:

    bool isSubseq(string a,string b){
        int N=a.length(); int M=b.length();

        if(M-N!=1) return false;

        int i=0;int j=0;
        while(i<N && j<M){
            if(a[i]==b[j]) i++;
            j++;
        }
        return i==N;
    }

    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[](string a,string b){return a.length()<b.length();});
        vector<int> dp(n,1);
        int maxLen=INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(isSubseq(words[j],words[i])){
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
            maxLen=max(maxLen,dp[i]);
        }
        return maxLen;
    }
};