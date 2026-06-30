// Last updated: 30/06/2026, 19:33:06
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        for(int i=1;i<=nums.size()-1;i++){
            int key=nums[i];
            int j=i-1;
            while(j>=0 && nums[j]>key){
                nums[j+1]=nums[j];
                j--;
            }
            nums[j+1]=key;
        }

        int max1=nums[nums.size()-1];int max2=0;int max3=0;
        int index=0;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]!=max1){
                max2=nums[i];
                index=i;
                break;
            }
        }
        for(int i=index;i>=0;i--){
            if(nums[i]!=max2){
                max3=nums[i];
                return max3;
            }
        }
        return max1;
        
    }
};