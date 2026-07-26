// brute froce is obvio using extra array

// 2nd approach is obvio 2-pointer
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int n=nums.size();
//         int k=0;
//         for(int i=0;i<n;i++){
//             if(nums[i]!=val){
//                 nums[k]=nums[i];
//                 k++;
//             }
//         }
//         return k;
//     }
// };

// eaiser to think of method
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int i=0;
        int j=n-1;

        while(i<=j){
            if(nums[i]==val){
                nums[i]=nums[j];
                j--;
            }
            else{
            i++;
            } 
        }
        return j+1;
    }
};