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
class BSTIterator {
private:
    vector<int> arr;
    int i=0;

    void dfs(TreeNode* node){
        if(!node) return;
        dfs(node->left);
        arr.push_back(node->val);
        dfs(node->right);
    }
public:
    BSTIterator(TreeNode* root) {
        i=0;
        dfs(root);
    }
    
    int next() {
        return arr[i++];
        
    }
    
    bool hasNext() {
        return i<arr.size();
    }
};