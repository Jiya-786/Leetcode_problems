// using bfs and reversing when req
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        if(root==nullptr) return result;
        int lvl=0;

        q.push(root);

        while(!q.empty()){
            int n=q.size();
            vector<int> currentLevel;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();

                currentLevel.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
            }
            if(lvl%2!=0){ reverse(currentLevel.begin(),currentLevel.end());
            }

            result.push_back(currentLevel);
            lvl++;


        } 
        return result;
    }
};