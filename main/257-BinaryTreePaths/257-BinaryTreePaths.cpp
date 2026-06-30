// Last updated: 30/06/2026, 19:33:57
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

//  // RECURSIVE DFS
// // class Solution {
// // public:
// //     vector<string> binaryTreePaths(TreeNode* root) {
// //         vector<string> result;
// //         dfsPath(root,"",result);
// //         return result;
// //     }
// // private:
// //     void dfsPath(TreeNode* root,string path,vector<string> result){
// //         if(!node) return;

// //         if(node->left==nullptr && node->right==nullptr){
// //             path+=node->val;
// //             result.push_back(path);
// //             return path;
// //         }

// //         else{
// //             path+=node->val;
// //             path+="->";
// //             dfs(node->left,path,result);
// //             dfs(node->right,path,result);
// //         }
// //     }
// // };

// // ITERATIVE DFS using stack
// class Solution {
// public:
//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string> result;
//         stack<pair<TreeNode*,string>> st;
//         if(!root) return result;

//         st.push({root,to_string(root->val)});

//         while(!st.empty()){
//             auto [node,path]=st.top();
//             st.pop();

//             // if its a leaf, save its path
//             if(node->left==nullptr && node->right==nullptr){
//                 result.push_back(path);
//                 continue;
//             }

//             else{
//                 if(node->left) st.push({node->left,path+"->"+to_string(node->left->val)});     // not path=path+"->"+to_string(node->left->val) because that will
//                                                                                                     // change the path for the right child node also, instead, just 
//                                                                                                     // add to path and push
//                 if(node->right) st.push({node->right,path+"->"+to_string(node->right->val)});
//             }
//         }
//         return result;
//     }
// };

// DFS with backtracing to avoid making new path for every recursive call, instead just using one pathList arr for all calls
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<string> pathList;

        dfs(root, pathList, result);

        return result;
    }

    void dfs(TreeNode* node, vector<string>& pathList, vector<string>& result) {
        if (node == nullptr) {
            return;
        }

        // Enter node
        pathList.push_back(to_string(node->val));

        // Leaf node
        if (node->left == nullptr && node->right == nullptr) {
            string path = "";

            for (int i = 0; i < pathList.size(); i++) {
                if (i > 0) {
                    path += "->";
                }
                path += pathList[i];
            }

            result.push_back(path);
        }
        else {
            dfs(node->left, pathList, result);
            dfs(node->right, pathList, result);
        }

        // Leave node (backtrack)
        pathList.pop_back();
    }
};