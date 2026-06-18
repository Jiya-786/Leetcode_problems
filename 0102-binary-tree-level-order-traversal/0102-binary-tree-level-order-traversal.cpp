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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);
        return result;
    }

private:
    void dfs(TreeNode* node, int level, vector<vector<int>>& result) {
        if (node == nullptr) return;

        // First time reaching this level, create a new list
        if (level == result.size()) {
            result.push_back({});
        }

        // Add current node's value to its level
        result[level].push_back(node->val);

        // Recurse left first to maintain left-to-right order
        dfs(node->left, level + 1, result);
        dfs(node->right, level + 1, result);
    }
};