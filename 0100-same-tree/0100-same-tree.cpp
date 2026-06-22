// we can do dfs on both and check if they give the same result, like write preorder fundtion and check of they return the same value
// but problem is it will only return non-null values
// there can be 2 trees which are not same but return the same values
// so it is imp that we record null values also in this approach
// instead, recursive dfs is the easiest in this case
// and it gives o(1) space, the 1st method gives o(n) 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;

        else if(p==nullptr || q==nullptr) return false;

        else if(p->val!=q->val) return false;

        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
}; 