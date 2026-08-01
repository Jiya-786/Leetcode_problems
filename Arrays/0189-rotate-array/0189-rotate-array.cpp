// // brute force. Rotate One by One
// // gives TLE
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n=nums.size();
//         k=k%n;

//         while(k--){
//             int last=nums[n-1];
//             for(int j=n-1;j>0;j--){
//                  nums[j]=nums[j-1];
//             }
//             nums[0]=last;
//         }
//    }
// };

// extra array
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n=nums.size();
//         k=k%n;
//         vector<int> temp(n);

//         for(int i=0;i<n;i++){
//             temp[(i+k)%n]=nums[i];
//         }

//         for(int i=0;i<n;i++){
//             nums[i]=temp[i];
//         }
//     }
// };

// reversing array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;

        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
    void reverse(vector<int>& nums,int left,int right){
        while(left<right){
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
    }
};