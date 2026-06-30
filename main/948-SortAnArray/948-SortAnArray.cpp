// Last updated: 30/06/2026, 19:32:13
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
private:
    void quickSort(vector<int>& nums,int l,int r){
        if(l<r){
            int p=hoarePartition(nums,l,r);
            quickSort(nums,l,p);
            quickSort(nums,p+1,r);
        }
    }

    int hoarePartition(vector<int>& nums,int l,int r){
        int pivot=nums[l];
        int i=l-1;
        int j=r+1;

        while(true){
            while( i+1<=r && nums[i+1]<pivot){
                i++;
            }
            while(j-1>=l && nums[j-1]>pivot){        // right pointer runs
            //from right end and checks for values smaller
            //than pivot hence, increment until greater than
            //pivot and stop otherwise similar logic for left
            //pointer

                j--;  
            }
            i++;j--;
            if(i>=j) return j;
            swap(nums[i],nums[j]);
            
        }
    }
};