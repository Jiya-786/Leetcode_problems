// Last updated: 30/06/2026, 19:30:26
// for every subarray [l,r] its sum is prefix[r]-prefix[l-1];
class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n=nums.size();
        vector<long long> prefixSum(n,0);
        prefixSum[0]=nums[0];

        for(int i=1;i<n;i++){
            prefixSum[i]+=(long long)nums[i]+prefixSum[i-1];
        }
        
        int count=0;
        for(int l=0;l<n;l++){
            long long sum=0;
            for(int r=l;r<n;r++){
                if(l==0){
                    sum=prefixSum[r];
                    if(validSum(sum,x)) count++;
                } 

                else{
                    sum=prefixSum[r]-prefixSum[l-1];
                    if(validSum(sum,x)) count++;
                }
                
            }
           
        }
        return count;
    }

private:
    bool validSum(long long sum,int k){
        bool ans=true;
        if(sum%10==k) ans=true;
        else return false;

        while(sum>=10){
            sum=sum/10;
        }
        if(sum==k) ans=true;
        else return false;

        return ans;
       
    }
};