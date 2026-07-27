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

// we wouldnt need 3 separate rules for befroe the first elt, middle elts, and last elts like in prev method
// we can just collapse it into one general rule
// using lower-1 and upper+1 as extra dummy elts
class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        vector<vector<int>> result;
        int prev=lower-1;

        for(int i=0;i<=n;i++){
            int curr=(i<n) ? nums[i] : upper+1;

            if(curr-prev!=1){
                result.push_back({prev+1,curr-1});
            }
            prev=curr;
        }
        return result;
    }
};
