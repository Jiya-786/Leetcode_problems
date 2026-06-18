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

                // this is just a slight variation of the first submission, instead of processing left-to-right and pushing the rightmost ie last elt into result, we process right to left and push the first node into result
                if(node->right) q.push(node->right);    // note: not result.push_back() or q.push_back()
                if(node->left) q.push(node->left);      // 
                
                // if(node->right) q.push(node->right);  
            }        
        }
        return result;

    }
};