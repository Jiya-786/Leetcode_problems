class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        unordered_set<int> deleteSet(to_delete.begin(), to_delete.end());

        // Build parent map using BFS
        unordered_map<TreeNode*, TreeNode*> parentMap;
        queue<TreeNode*> q;
        q.push(root);
        parentMap[root] = nullptr;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parentMap[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }

        // Process deletions with another BFS pass
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);

            if (deleteSet.count(node->val)) {
                TreeNode* parent = parentMap[node];
                if (parent) {
                    if (parent->left == node) parent->left = nullptr;
                    else parent->right = nullptr;
                }
                if (node->left && !deleteSet.count(node->left->val)) {
                    forest.push_back(node->left);
                }
                if (node->right && !deleteSet.count(node->right->val)) {
                    forest.push_back(node->right);
                }
            }
        }

        if (!deleteSet.count(root->val)) {
            forest.push_back(root);
        }
        return forest;
    }
};