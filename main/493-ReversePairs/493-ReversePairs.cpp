// Last updated: 30/06/2026, 19:32:52
// // TLE solution-
// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//          vector<long long> double_nums;
//          for(int i=0;i<nums.size();i++){
//             double_nums.push_back((long long)2*nums[i]);
//          }
//          int count=0;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[i]>double_nums[j]){
//                     count++;
//                 }
//             }

//         }
//         return count;
//     }
// };

//using merge sort to count number of inversions-optimal
// we can use the fact that during merging ofarray we can compare left half and right half
//chekc out count inversions video of shraddha khapra
class Solution {
public:
    int reversePairs(vector<int>& nums) {
         return mergeSort(nums,0,nums.size()-1);
    }
    int merge(vector<int>& nums,int left,int mid,int right){
            int i=0;int j=0;int k=0;
            i=left;
            j=mid+1;
            k=right;
            int countInv=0;

            int p = mid + 1;
            for (int i = left; i <= mid; i++) {
            while (p <= right && (long long)nums[i] > 2LL * nums[p]) {
                p++;
            }
            countInv += (p - (mid + 1));
            }
            vector<int> ans;
            while(i<=mid && j<=right){
                if(nums[i]<=nums[j]){
                    ans.push_back(nums[i]);
                    i++;
                }
                else{
                    ans.push_back(nums[j]);
                    j++;
                    // if((long long)nums[i]>2LL*nums[j]){
                    //     countInv+=(mid-i+1);
                    // }                           this is for normal inversion counting.
                                                   //won't work here since this will impose 2
                                                   //conditions nums[i]>nums[j] and nums[i
                                                   //>2*nums[j] but for our qs its not
                                                   //mandatory for both conditions to hold we
                                                   //only need 2nd condition to hold in our
                                                   //case so this is not how we will count.
                }
            }
            while(i<=mid){
                ans.push_back(nums[i]);
                i++;
            }
            while(j<=right){
                ans.push_back(nums[j]);
                j++;
            }
            for(int k = 0; k < ans.size(); k++) {
                nums[left + k] = ans[k];
            }
            return countInv;
        }

        int mergeSort(vector<int>& nums,int left,int right){
            if(left<right){
                int mid=(right+left)/2;
                int LeftCountInv=mergeSort(nums,left,mid);
                int RightCountInv=mergeSort(nums,mid+1,right);
                int CountInv=merge(nums,left,mid,right);
                return LeftCountInv+RightCountInv+CountInv;
            }
            return 0;
            
        }

        // vector<int> sortArray(vector<int>& nums) {
        //     mergeSort(nums,0,nums.size()-1);
        //     return nums;
        // }

};


