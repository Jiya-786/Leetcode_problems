// Last updated: 30/06/2026, 19:32:29
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// // ITERATIVE INORDER TRAVERSAL
// class Solution {
// public:
//     int minDiffInBST(TreeNode* root) {
//         stack<TreeNode*> st;
//         vector<int> result;
//         TreeNode* curr=root;
        
//         // st.push(root);       // not req since we are already pushing inside the while loop
//         while(curr||!st.empty()){
//             while(curr){
//                 st.push(curr);
//                 curr=curr->left;
//             }
//             curr=st.top();
//             st.pop();
//             result.push_back(curr->val);

//             curr=curr->right;
//         }

//         int mini=INT_MAX;
//         for(int i=1;i<result.size();i++){
//             mini=min(mini,abs(result[i]-result[i-1]));
//         }

//         return mini;
//     }
// };

// RECURSIVE INORDER TRAVERSAL
// class Solution {
// public:
//     int minDiffInBST(TreeNode* root) {
//         vector<int> result;
//         inorder(root,result);

//         int mini=INT_MAX;
//         for(int i=1;i<result.size();i++){
//             mini=min(mini,abs(result[i]-result[i-1]));
//         }
//         return mini;
//     }
// private: 
//     void inorder(TreeNode* node,vector<int>& result){
//         if(node==nullptr) return;

//         inorder(node->left,result);
//         result.push_back(node->val);
//         inorder(node->right,result);
//     }
// };

// SPACE OPTIMIZED RECURSIVE DFS
// instead of sotring all elts in array, compare on the go while mainitaing a prev node pointer
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int res=INT_MAX;
        TreeNode* prev=nullptr;

        dfs(root,prev,res);

        return res;
    }
private:
    void dfs(TreeNode* node, TreeNode*& prev, int& res){
        if(!node) return;

        dfs(node->left,prev,res);
        if(prev) res=min(res,abs(node->val-prev->val));
        prev=node;
        dfs(node->right,prev,res);

    }
};