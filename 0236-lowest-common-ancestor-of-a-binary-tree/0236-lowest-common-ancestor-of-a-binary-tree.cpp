class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Build parent map using BFS
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> bfsQueue;
        parent[root] = nullptr;
        bfsQueue.push(root);

        // BFS until we've found both p and q's parents
        while (parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
            TreeNode* node = bfsQueue.front();
            bfsQueue.pop();
            if (node->left) {
                parent[node->left] = node;
                bfsQueue.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                bfsQueue.push(node->right);
            }
        }

        // Trace p's ancestors into a set
        unordered_set<TreeNode*> ancestors;
        TreeNode* current = p;
        while (current != nullptr) {
            ancestors.insert(current);
            current = parent[current];
        }

        // Walk q upward until we find a common ancestor
        current = q;
        while (ancestors.find(current) == ancestors.end()) {
            current = parent[current];
        }

        return current;
    }
};