// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right; *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

// RECURSIVE SOLUTION
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> result;
//         preorder(root,result);
//         return result;
//     }
// private:
//     void preorder(TreeNode* node,vector<int>& result){
//         if(node==nullptr) return;

//         result.push_back(node->val);
//         preorder(node->left,result);
//         preorder(node->right,result);
//     }
// };

// ITERATIVE SOLUTION USING STACK
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;

        if(root==nullptr) return result;
        s.push(root);

        while(!s.empty()){
            TreeNode* node=s.top();
            result.push_back(node->val);
            s.pop();

            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }

        return result;
        
    }
};