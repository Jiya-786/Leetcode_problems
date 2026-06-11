// hash-set will give a better solution than hash-map beciase we only need to know whether or not the number exists, not how many times it exists
// time o(n)
// space o(n)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());

        int counter=1;
        while(true){
            if(st.find(counter)==st.end()){
                return counter;
            }
            else counter++;
        }
        return -1;
    }
};