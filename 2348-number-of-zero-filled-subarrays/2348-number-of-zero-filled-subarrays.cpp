// // brute force
// class Solution {
// public:
//     long long zeroFilledSubarray(vector<int>& nums) {
//         long long count = 0;

//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] != 0) continue;
//             for (int j = i; j < nums.size() && nums[j] == 0; j++) {
//                 count++;
//             }
//         }
//         return count;
//     }
// };

// optimized
// on time
// chacking number of consecutive zeroes
// for k consecutive zeroes we get k*k+1/2 zeroes
// becuase for k numbers we have k+1 boundaries, and for a subarray we choose any 2, so k+1c2, so k+1*k/2
// here max n=10^5 so at max there can be n consecutive zeroes
// so at max ~10^10/2 ~ 5*10^9 can be the ans
// 5*10^9 will not fit in int
// hence we need to use long long
// class Solution {
// public:
//     long long zeroFilledSubarray(vector<int>& nums) {
//         int n=nums.size();
//         long long count=0;

//         int i=0;
//         while(i<n){
//             if(nums[i]!=0){
//                 i++;
//             } 
//             else{
//                 long long x=0;
//                 while(i<n && nums[i]==0){
//                     x++;
//                     i++;
//                 }
//                 count+=((x)*(x+1)/2);
//             }
//         }
//         return count;
//     }
// };

// cleaner optimized soln
// just a diff counting method
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        int consecutive=0;

        for(int i=0;i<n;i++){
            if(nums[i]==0) consecutive+=1;
            else consecutive=0;

            ans+=consecutive;
        }
        return ans;
    }
};