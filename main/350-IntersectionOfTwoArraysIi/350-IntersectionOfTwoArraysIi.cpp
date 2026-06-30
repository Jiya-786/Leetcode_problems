// Last updated: 30/06/2026, 19:33:17
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map1;
        unordered_map<int,int> map2;

        for(int i=0;i<nums1.size() || i<nums2.size();i++){
            if(i<nums1.size()) map1[nums1[i]]++;
            if(i<nums2.size()) map2[nums2[i]]++;
        }

        int occurances;
        vector<int> ans;
        for(auto it:map1){
            // if(nums2[it.first]>=1 && it.second>=1){
            //     ans.push_back(it.first);
            // }
            occurances=min(map2[it.first],it.second);
            for(int i=0;i<occurances;i++){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};