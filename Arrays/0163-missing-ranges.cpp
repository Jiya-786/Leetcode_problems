// chackign each gap separately
// on time o1 space

class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        vector<vector<int>> result;

        if(n==0){
            result.push_back({lower,upper});
            return result;
        }
        if(lower<nums[0]){
            result.push_back({lower,nums[0]-1});
        }
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i]>1){
                result.push_back({nums[i]+1,nums[i+1]-1});
            }
        }
        if(nums[n-1]<upper){
            result.push_back({nums[n-1]+1,upper});
        }

        return result;

    }
};
