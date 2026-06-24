// ITERATIVE INORDER TRAVERSAL
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        TreeNode* curr=root;
        
        // st.push(root);       // not req since we are already pushing inside the while loop
        while(curr||!st.empty()){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            result.push_back(curr->val);

            curr=curr->right;
        }

        int mini=INT_MAX;
        for(int i=1;i<result.size();i++){
            mini=min(mini,abs(result[i]-result[i-1]));
        }

        return mini;
    }
};