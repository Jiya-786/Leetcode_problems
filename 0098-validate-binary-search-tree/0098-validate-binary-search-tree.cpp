// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

//  // BRUTE FORCE
// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         if(!root) return true;

//         if(!(allLessThan(root->left,root->val) && allGreaterThan(root->right,root->val))) return false;

//         return isValidBST(root->left) && isValidBST(root->right);
//     }
// private:
//     bool allLessThan(TreeNode* node, int val){
//         if(!node) return true;
//         if(node->val >= val) return false;
//         return allLessThan(node->left,val) && allLessThan(node->right,val);
//     }
//     bool allGreaterThan(TreeNode* node,int val){
//         if(!node) return true;
//         if(node->val<=val) return false;
//         return allGreaterThan(node->left,val) && allGreaterThan(node->right,val);
//     }
// };

// RECURSIVE RANGE VALIDATION
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root,LONG_MIN,LONG_MAX);
    }
private:
    bool validate(TreeNode* node,long lower,long upper){
        if(!node) return true;

        if(node->val<=lower || node->val>=upper) return false;

        return validate(node->left,lower,node->val) && validate(node->right,node->val,upper);
    }
};