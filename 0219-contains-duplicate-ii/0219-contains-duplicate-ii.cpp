// using hashmap to store latest index becuase if elt is at position 2,7,15 nad we are checking at position 17 with k=3 and 15 does not satisfy, defi 2 nad 7 will also not satisfy
// time o(n)
// space o(n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> lastSeen;
        for(int i=0;i<nums.size();i++){
            if(lastSeen.count(nums[i]) && (i-lastSeen[nums[i]]<=k)){
                return true;
            }
            lastSeen[nums[i]]=i;
        }
        return false;
    }
};