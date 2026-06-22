class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        // Both null means both subtrees are empty — they mirror each other
        if (left == nullptr && right == nullptr) {
            return true;
        }
        // One null and one non-null means structural mismatch
        if (left == nullptr || right == nullptr) {
            return false;
        }
        // Values must match, and cross-children must be mirrors
        return left->val == right->val
            && isMirror(left->left, right->right)
            && isMirror(left->right, right->left);
    }
};