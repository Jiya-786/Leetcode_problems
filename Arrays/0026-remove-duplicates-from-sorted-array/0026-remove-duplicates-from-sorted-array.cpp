// // using hash-set
// // this is not inplace
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int n=nums.size();
//         unordered_set<int> seen(nums.begin(),nums.end());
//         vector<int> unique(seen.begin(),seen.end());
//         sort(unique.begin(),unique.end());
//         int k=unique.size();

//         for(int i=0;i<k;i++){
//             nums[i]=unique[i];
//         }

//         return k;

//     }
// };

// two pointer swapping method
// in-place
//                i                        j   
// 1    2    3    4    5    3    4    4    5
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0; int j=1;
        while(j<n){
            if(nums[i]!=nums[j]){
                nums[i+1]=nums[j];
                i++;
            }
            j++;
            
        }
        return i+1;
    }
};