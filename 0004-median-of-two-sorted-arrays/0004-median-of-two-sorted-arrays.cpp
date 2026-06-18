// USING MERGE TWO SORTED ARRAYS
// time o(n+m)
// space o(n+m)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(); int m=nums2.size();
        int t=n+m;
        vector<int> merged(t);
        int k=0; int i=0; int j=0;

        while(i<n && j<m){   // not: for(int i=0;i<n && int j=0;j<m)
            if(nums1[i]<=nums2[j]){
                merged[k]=nums1[i];
                i++;k++;
            }
            else{
                merged[k]=nums2[j];
                j++;k++;
            }
        }

        while(i<n){    // we have to declare i and j outside for them to exist, rn, i defined 
                       // them inside the for loop hence wouldn't work
            merged[k]=nums1[i];
            i++;k++;
        }
        while(j<m){
            merged[k]=nums2[j];
            j++;k++;
        }

        double ans;
        if(t%2==0){
            ans=(merged[t/2]+merged[(t/2)-1])/2.0;
        }
        else{
            ans=merged[t/2];
        }

        return ans;
    }
};