// brute force
// give TLE obvio
// class Solution {
// public:
//     bool increasingTriplet(vector<int>& nums) {
//         int n=nums.size();
//         bool ans;

//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 if(nums[i]<nums[j]){
//                     for(int k=j;k<n;k++){
//                         if(nums[j]<nums[k]){
//                             return true;
//                         }
//                     }
//                 }
//             }
//         }
//         return false;
//     }
// };


// optimized 2-pointer approach
// watch MIKS vid for greatest level of clarity and reasoning
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int first=INT_MAX;
        int second=INT_MAX;

        for(int i=0;i<n;i++){
            if(nums[i]<=first){
                first=nums[i];
            }
            else if(nums[i]<=second){
                second=nums[i];
            }
            else{
                return true;
            }
        }
        return false;
    }
};