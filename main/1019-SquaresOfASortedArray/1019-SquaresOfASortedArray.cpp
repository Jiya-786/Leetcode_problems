// Last updated: 30/06/2026, 19:31:18
// this is not the most optimal solution since o(n)+o(nlogn)-> due to sort
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             if(nums[i]<0){
//                 nums[i]=-(nums[i]);
//             }
//         }
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<n;i++){
//             nums[i]=nums[i]*nums[i];
//         }
//         return nums;
//     }
// };

// better solution using two pointer method-
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);

        int l=0;int r=n-1;int pos=n-1;
        while(l<=r){
            if(abs(nums[l])>abs(nums[r])){
                ans[pos]=nums[l]*nums[l];
                l++;
                pos--;
            }
            else{
                ans[pos]=nums[r]*nums[r];
                r--;
                pos--;
            }
        }
        return ans;
    }
};
