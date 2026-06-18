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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root==nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int levelSize=q.size();

            for(int i=0;i<levelSize;i++){
                TreeNode* node=q.front();
                q.pop();

                // the last node is the right side view
                if(i==0){
                    result.push_back(node->val);
                }

                if(node->right) q.push(node->right);    // not result.push_back()
                if(node->left) q.push(node->left);      // not q.push_back()
                // if(node->right) q.push(node->right);    // not result.push_back()
            }        
        }
        return result;

    }
};