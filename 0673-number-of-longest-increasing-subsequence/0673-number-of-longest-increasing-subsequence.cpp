// DP bottom-up approach
// top-down recursive is a bit tricky for this variant of LIS
// time o(n^2)
// first understnad simple LIS bottom-up dry run then come to this for better idea of idea
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return 1;

        vector<int> t(n,1);
        vector<int> count(n,1);                                                                          

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(t[j]+1==t[i]){
                        count[i]+=count[j];
                    }
                    else if(t[j]+1>t[i]){
                        count[i]=count[j];
                        t[i]=t[j]+1;
                    }
                }
            }
        }
        int maxVal=*max_element(t.begin(),t.end());

        int ans=0;
        for(int i=0;i<n;i++){
            if(t[i]==maxVal) ans+=count[i];
        }
        return ans;
    }
};