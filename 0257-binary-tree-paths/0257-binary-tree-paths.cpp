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

 // RECURSIVE DFS
// class Solution {
// public:
//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string> result;
//         dfsPath(root,"",result);
//         return result;
//     }
// private:
//     void dfsPath(TreeNode* root,string path,vector<string> result){
//         if(!node) return;

//         if(node->left==nullptr && node->right==nullptr){
//             path+=node->val;
//             result.push_back(path);
//             return path;
//         }

//         else{
//             path+=node->val;
//             path+="->";
//             dfs(node->left,path,result);
//             dfs(node->right,path,result);
//         }
//     }
// };

// ITERATIVE DFS
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        stack<pair<TreeNode*,string>> st;
        if(!root) return result;

        st.push({root,to_string(root->val)});

        while(!st.empty()){
            auto [node,path]=st.top();
            st.pop();

            // if its a leaf, save its path
            if(node->left==nullptr && node->right==nullptr){
                result.push_back(path);
                continue;
            }

            else{
                if(node->left) st.push({node->left,path+"->"+to_string(node->left->val)});     // not path=path+"->"+to_string(node->left->val) because that will
                                                                                                    // change the path for the right child node also, instead, just 
                                                                                                    // add to path and push
                if(node->right) st.push({node->right,path+"->"+to_string(node->right->val)});
            }
        }
        return result;
    }
};