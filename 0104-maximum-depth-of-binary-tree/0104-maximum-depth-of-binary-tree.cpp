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

// // RECURSIVE APPROACH
// // DFS approach
// // max depth at a given node= 1+max depth of left/right subtree 
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root==nullptr) return 0;
//         int leftDepth=maxDepth(root->left);
//         int rightDepth=maxDepth(root->right);
//         return 1+max(leftDepth,rightDepth);
//     }
// };

// iterative BFS approach 
// level order traversal basically
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==nullptr) return 0;
        q.push(root);
        int depth=0;

        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};

