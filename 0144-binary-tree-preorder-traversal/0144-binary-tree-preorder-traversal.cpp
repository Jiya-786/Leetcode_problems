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

// // ITERATIVE SOLUTION USING STACK
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> result;
//         stack<TreeNode*> s;

//         if(root==nullptr) return result;
//         s.push(root);

//         while(!s.empty()){
//             TreeNode* node=s.top();
//             result.push_back(node->val);
//             s.pop();

//             if(node->right) s.push(node->right);
//             if(node->left) s.push(node->left);
//         }

//         return result;
        
//     }
// };

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

// MORRIS TRAVERSAL
// gives o(1) space optimization
// recursive and itertive give o(n) 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr=root;

        while(curr!=nullptr){
            if(curr->left==nullptr){
                result.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* req=curr->left;
                while(req->right!=nullptr && req->right!=curr){
                    req=req->right;
                }
                if(req->right==nullptr){  // this would be our first visit
                    req->right=curr;   // create thread
                    result.push_back(curr->val);
                    curr=curr->left;
                }
                else{         // this would be our 2nd visit
                    req->right=nullptr;   // break the thread;
                    curr=curr->right;
                }
            }
        }
        return result;
    }
};

