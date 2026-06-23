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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = false;
        Tree(root,targetSum,sum,ans);
        return ans;
    }
    void Tree(TreeNode *root, int targetSum, int sum, bool &ans){
        if(root == nullptr) return;
        sum += root->val;
        if(root->left == nullptr && root->right == nullptr){
            if(sum == targetSum) ans = true;
            return;
        }
        Tree(root->left,targetSum,sum,ans);
        Tree(root->right,targetSum,sum,ans);
    }
};