// simple running count           
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int currStreak=0;
        int maxStreak=0;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                // maxStreak=max(currStreak,maxStreak);
                currStreak=0;
                // continue;
            }
            else currStreak++;

            maxStreak=max(currStreak,maxStreak);
        }
        return maxStreak;
    }
};