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

// // ITERATIVE BFS
// class Solution {
// public:
//     vector<double> averageOfLevels(TreeNode* root) {
//          queue<TreeNode*> q;
//          q.push(root);          // given min 1 node exists hence if(root==nullptr) is not req

//          vector<double> result;

//          while(!q.empty()){
//             int n=q.size();
//             int long long sum=0;
//             for(int i=0;i<n;i++){
//                 TreeNode* node=q.front();
//                 q.pop();
//                 sum+=node->val;

//                 if(node->left) q.push(node->left);
//                 if(node->right) q.push(node->right);
//             }
//             result.push_back((double)sum/n);
//          }
//          return result;

//     }
// };

// DFS METHOD
// it might look like level order/bfs but its dfs since we do root->left->right
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<long long> sums;
        vector<int> counts;

        dfs(root,0,sums,counts);

        vector<double> result;
        for(int i=0;i<counts.size();i++){
            result.push_back((double)sums[i]/counts[i]);
        }

        return result;

    }
private:
    void dfs(TreeNode* node,int depth,vector<long long>& sums,vector<int>& counts){
        if(depth==sums.size()){
            sums.push_back(node->val);
            counts.push_back(1);
        }
        else{
            sums[depth]+=node->val;
            counts[depth]++;
        }
        if(node->left) dfs(node->left,depth+1,sums,counts);
        if(node->right) dfs(node->right,depth+1,sums,counts);
    }
};