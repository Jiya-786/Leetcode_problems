// BRUTE FORCE
// time o(n3)
// space o(1)
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>> ans;
//         int n=nums.size();

//         for(int i=0;i<n-2;i++){
//             for(int j=i+1;j<n-1;j++){
//                 for(int k=j+1;k<n;k++){
//                     if(nums[i]+nums[j]+nums[k]==0){
//                         vector<int> triplet={nums[i],nums[j],nums[k]};
//                         sort(triplet.begin(),triplet.end());
//                         ans.insert(triplet);
//                     }
//                 }
//             }
//         }
//         return vector<vector<int>>(ans.begin(),ans.end());
//     }
// };

// SORTING + TWO-POINTER
// time o(n2)
// space o(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                break;
            }

            if(i>=1 && nums[i]==nums[i-1]){
                continue;
            }
            
            else{
                int left=i+1;int right=n-1;
                while(left<right){
                    if(nums[i]+nums[left]+nums[right]==0){
                        ans.push_back({nums[i],nums[left],nums[right]});
                        // left++;right--;  // this is imp so the while loop remains finite
                        while(left<right && nums[left]==nums[left+1]) left++;
                        while(left<right && nums[right]==nums[right-1]) right--;
                        left++; right--;  // this is imp so the while loop remains finite

                    }
                    else if(nums[i]+nums[left]+nums[right]<0){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};
