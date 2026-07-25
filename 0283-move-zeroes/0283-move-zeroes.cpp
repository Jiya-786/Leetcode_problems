// 2-pointer swapping method
// insertPos will keep track of next pos of non-zero elt, and we keep swapping into it everytime there is a non-zero elt.
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int insertPos=0;

        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[insertPos]);
                insertPos++;
            }
        }
    }
};