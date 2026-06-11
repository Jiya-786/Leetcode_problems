// // brute force
// // multiply all numbers except self and store in result array
// // time o(n^2)
// // space o(1) since per problem result array is not considered extra space

// // TLE
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> result(nums.size());

//         for(int i=0;i<nums.size();i++){
//             int product=1;
//             for(int j=0;j<nums.size();j++){
//                 if(i!=j){
//                     product*=nums[j];
//                 }
//             }
//             result[i]=product;
//         }
//         return result;
//     }
// };

// maintain a prefix and suffix array
// prefix array contains product of all elts before the ith elt
// suffix array contains product of all elts after the ith elt
// final result will be prefix*suffix 
// time o(n)
// space o(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n),prefix(n),suffix(n);

        prefix[0]=1;
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        suffix[n-1]=1;
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i+1];
        }

        for(int i=0;i<n;i++){
            result[i]=prefix[i]*suffix[i];
        }
        return result;
    }
};