// this logic itself is worng this is not what we want
// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) {
//         int i=1;
//         int j=n;
//         while(i<=n-1 && j<=2*n-1 && i!=j){
//             int temp=nums[i];
//             nums[i]=nums[j];
//             nums[j]=temp;
//             i++;
//             j++;
//         }
//         return nums;
//     }

// };

// using an extra array
// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) {
//         vector<int> x_values;
//         vector<int> y_values;

//         for(int i=0;i<n;i++){
//             x_values.push_back(nums[i]);
//         }
//         for(int i=n;i<2*n;i++){
//             y_values.push_back(nums[i]);
//         }
//         for(int i=0;i<n;i++){
//             nums[2*i]=x_values[i];
//             nums[2*i+1]=y_values[i];
//         }
//         return nums;
//     }

// };

// doesnt't even req making 2 x,y values arryas, just do directly
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result(2*n,0);

        for(int i=0;i<n;i++){
            result[2*i]=nums[i];
            result[2*i+1]=nums[n+i];
        }
        return result;
    }
};