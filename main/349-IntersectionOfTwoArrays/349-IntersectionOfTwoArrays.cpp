// Last updated: 30/06/2026, 19:33:20
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> freq1;
        for(int i=0;i<=1000;i++){
            freq1.push_back(0);
        }
        vector<int> freq2;
        for(int i=0;i<=1000;i++){
            freq2.push_back(0);
        }
        for(int i=0;i<nums1.size();i++){
            freq1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            freq2[nums2[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<=1000;i++){
            if(freq1[i]!=0 && freq2[i]!=0){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};