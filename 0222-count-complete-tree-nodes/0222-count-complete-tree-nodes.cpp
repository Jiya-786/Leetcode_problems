// // BRUTE FORCE- direct dfs without using complete binary tree property
// // o(n) time, but qs asks for <o(n) time
// // can also do simple bfs, but this is shorter to write-just 2 lines, for bfs we will have to make a queue n all
// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         if(root==nullptr) return 0;
//         return 1+ countNodes(node->left)+countNodes(node->right);
//     }
// };

// definiton of complete binary tree is all nodes will hve 2 children expcept possibly the last level
// if the last level has children, they will be filled starting from left
// definiton of perfect binary tree is that all nodes have 2 children and all leaf nodes will be at same height
// so in case the given complete binary tree is not perfect, it is guaranteed that one of its subtrees will be perfect
// becuase a complete binary tree leats say has 1/2 leftmost childnode at the last level- then the right subtree is perfect
// if it has 3 leftmost childnodes then left subtree will be prefect and for 4 child nodes in last level, entire tree will be prefect
// we will make use of the fact thant in a perfect binary tree number of nodes are 2^h-1
class Solution {
public:
    int lh(TreeNode* root){
            int h=0;
            while(root){
                h++;
                root=root->left;
            }
            return h;
        }
    int rh(TreeNode* root){
        int h=0;
        while(root){
            h++;
            root=root->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        if(lh(root)==rh(root)){
            return ((1<<lh(root))-1);                     // 1 << n = 2^n
        }

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};