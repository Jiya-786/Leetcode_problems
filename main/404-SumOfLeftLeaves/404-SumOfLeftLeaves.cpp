// Last updated: 30/06/2026, 19:33:08
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
// class Solution {
// public:
//     int sumOfLeftLeaves(TreeNode* root) {
//         if(!root) return 0;

//         int sum=0;
//         if(root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr){
//             sum+=root->left->val;
//         }
//         else{
//             sum+=sumOfLeftLeaves(root->left);
//         }

//         sum+=sumOfLeftLeaves(root->right);

//         return sum;
//     }
// };

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Check if the left child is a leaf
            if (node->left != nullptr) {
                if (node->left->left == nullptr && node->left->right == nullptr) {
                    sum += node->left->val;
                } else {
                    q.push(node->left);
                }
            }

            // Always enqueue the right child if it exists
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }

        return sum;
    }
};