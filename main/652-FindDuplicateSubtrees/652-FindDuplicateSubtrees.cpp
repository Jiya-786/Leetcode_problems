// Last updated: 30/06/2026, 19:32:33
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string, int> count;
        serialize(root, count, result);
        return result;
    }

private:
    string serialize(TreeNode* node, unordered_map<string, int>& count, vector<TreeNode*>& result) {
        if (!node) return "#";

        // Build postorder serialization: left, right, current
        string serial = serialize(node->left, count, result) + ","
                      + serialize(node->right, count, result) + ","
                      + to_string(node->val);

        count[serial]++;

        // Add to result only on the second occurrence
        if (count[serial] == 2) {
            result.push_back(node);
        }

        return serial;
    }
};