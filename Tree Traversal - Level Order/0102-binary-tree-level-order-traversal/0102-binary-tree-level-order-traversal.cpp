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
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> result;
//         dfs(root,0,result);
//         return result;
//     }
// private:
//     void dfs(TreeNode* node, int level, vector<vector<int>>& result){
//         if(node==nullptr) return;

//         // if first time at this level
//         if(level==result.size()){
//             result.push_back({});
//         }

//         // add current node's value to this level
//         result[level].push_back(node->val);

//         // recurse left to maintain left to right order
//         dfs(node->left,level+1,result);
//         dfs(node->right,level+1,result);

//     }
// };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int levelSize=q.size();
            vector<int> currentLevel;

            for(int i=0;i<levelSize;i++){
                TreeNode* node=q.front();
                q.pop();
                currentLevel.push_back(node->val);

                // enqueue children for next level
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            result.push_back(currentLevel);
        }
        return result;
    }
};