// Last updated: 30/06/2026, 19:33:39
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int> sorted=nums;
        sort(sorted.begin(),sorted.end());

        int mid=(n+1)/2;
        int j=mid-1;
        int k=n-1;

        for(int i=0;i<n;i++){
            if(i%2==0){
                nums[i]=sorted[j];
                j--;
            }
            else{
                nums[i]=sorted[k];
                k--;
            }
        }
    }
};