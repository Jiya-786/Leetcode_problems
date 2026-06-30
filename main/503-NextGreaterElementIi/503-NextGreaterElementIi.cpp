// Last updated: 30/06/2026, 19:32:48
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            if(st.empty()){
                ans[i%n]=-1;
            }
            else{
                ans[i%n]=st.top();
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};