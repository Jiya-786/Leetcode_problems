// we can use the input array itself as a hashmap
// the answer is always in the range [1,n+1]
// we want to check which numbers from 1 to n are present and which are not
// value i at index i-1
// then first index where mismatch happens is the ans 
// this is cycle sort
// for each position we keep swapping the current elt to its correct position until- 
            //   either the current elt is out of range(-ve,0, or >n)
            //   current elt is already in correct position
            //   target position already has correct value(duplicate)
// after this arrangement, one pass through the array gives us the ans

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();

        // place each value i at index i-1 using cycle sort
        for(int i=0;i<n;i++){
            while(nums[i]>=1 && nums[i]<=n && nums[nums[i]-1]!=nums[i]){     // this handles
                                                                             // <=0, >n 
                                                                             // duplicates
                swap(nums[i],nums[nums[i]-1]);
            }
        }

        // find the first position where the value does not match
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};