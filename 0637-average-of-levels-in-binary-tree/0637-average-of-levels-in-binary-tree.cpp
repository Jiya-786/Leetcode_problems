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

// ITERATIVE BFS

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
         queue<TreeNode*> q;
         q.push(root);          // given min 1 node exists hence if(root==nullptr) is not req

         vector<double> result;

         while(!q.empty()){
            int n=q.size();
            int long long sum=0;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                sum+=node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            result.push_back((double)sum/n);
         }
         return result;

    }
};