// // BRUTE FORCE
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         // Simple scan through every element
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == target) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0; int right=n-1;

        while(left<=right){
            int mid=right+(left-right)/2;

            if(nums[mid]==target){
                return mid;
            }

            else if(nums[left]<=nums[mid]){ // implies left half is sorted
                if(nums[left]<=target && nums[mid]>target){  // can't be nums[mid]>=target
                                                              // since if = was ture, it would 
                                                              // have already returned it in 
                                                              // the first if statement
                  right=mid-1;     
                }
                else{
                    left=mid+1;
                }
            }
            else{   // right half is sorted
                if(target>nums[mid] && target<=nums[right]){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }


        }
        return -1;
    }
};