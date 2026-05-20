class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         for(int j=i;j<nums.size()-1;j++){
        //                 nums[j]=nums[j+1];
        //         }
        //         nums[nums.size()-1]=0;
        //     }
        // }

        vector<int> answer;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                answer.push_back(nums[i]);
            }
            else count++;
        }
        for(int i=0;i<count;i++){
            answer.push_back(0);
        }

        nums=answer;



    }
};