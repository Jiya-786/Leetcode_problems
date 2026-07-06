// // BRUTE FORCE 
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int first = -1;
//         int last = -1;

//         // Find first occurrence
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == target) {
//                 first = i;
//                 break;
//             }
//         }

//         // If target not found, no need to search for last
//         if (first == -1) {
//             return {-1, -1};
//         }

//         // Find last occurrence
//         for (int j = nums.size() - 1; j >= 0; j--) {
//             if (nums[j] == target) {
//                 last = j;
//                 break;
//             }
//         }

//         return {first, last};
//     }
// };

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=lowerBound(nums,target);

        if(first==nums.size()||nums[first]!=target){
            return {-1,-1};        
        }

        int last=upperBound(nums,target)-1;
        return {first,last};
    }

private:
    int lowerBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    // Finds the first index where nums[i] > target
    int upperBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};

