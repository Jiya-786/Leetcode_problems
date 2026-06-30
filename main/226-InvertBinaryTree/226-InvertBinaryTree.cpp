// Last updated: 30/06/2026, 19:34:25
// // /**
// //  * Definition for a binary tree node.
// //  * struct TreeNode {
// //  *     int val;
// //  *     TreeNode *left;
// //  *     TreeNode *right;
// //  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// //  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// //  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// //  * };
// //  */

// // //  BFS SOLUTION 
// // class Solution {
// // public:
// //     TreeNode* invertTree(TreeNode* root) {
// //         queue<TreeNode*> q;
// //         if(!rooe) return nullptr;

// //         while(!q.empty()){
// //             TreeNode* node=q.front();
// //             q.pop();

// //             TreeNode* temp=node->left;
// //             node->left=node->right;
// //             node->right=temp;

// //             if(node->left) q.push(node->left);
// //             if(node->right) q.[ush(node->right);
// //         }
// //         return root;
// //     }
// // };

// //  ITERATIVE DFS SOLUTION (with stack) 
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         stack<TreeNode*> st;
//         if(!root) return nullptr;

//         st.push(root);
//         while(!st.empty()){
//             TreeNode* node=st.top();
//             st.pop();

            
            
//             TreeNode* temp=node->left;
//             node->left=node->right;
//             node->right=temp;

//             if(node->left) st.push(node->left);
//             if(node->right) st.push(node->right);
//         }
//         return root;
//     }
// };

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;

        // Recursively invert both subtrees
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        // Swap the children
        root->left = right;
        root->right = left;

        return root;
    }
};