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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfsPath(root,"",result);
        return result;
    }
private:
    void dfsPath(TreeNode* node,string path,vector<string>& result){
        if(!node) return;

        if(node->left==nullptr && node->right==nullptr){
            path+=to_string(node->val);                 // not just path+=node->val; it will push 1 as u001 etc
            result.push_back(path);
        }

        else{
            path+=to_string(node->val);
            path+="->";
            dfsPath(node->left,path,result);
            dfsPath(node->right,path,result);
        }
    }
};