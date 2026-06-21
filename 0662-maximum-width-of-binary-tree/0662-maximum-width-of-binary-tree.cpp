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

//  // BFS SOLUTION 
// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         queue<TreeNode*> q;
//         if(!root) return 0;
//         q.push(root);
//         int k=0;

//         int maxi=0;
//         while(!q.empty()){
//             int n=q.size();
//             maxi=max(n+k,maxi);
//             k=0;
//             for(int i=0;i<n;i++){
//                 TreeNode* node=q.front();
//                 q.pop();

//                 if(node->left) q.push(node->left);
//                 else if(node->right) q.push(node->right);
//                 else if(!node->left) k++;
//                 else if(!node->right) k++;
                
//             }
//         }
//         return maxi;
//     }
// };

// this does not work either, if we want to push all nulls into the array
// we can use a clever optimization trick to make the solution workable
// we dont need all nullptr positions, we only need all non-null nodes indices
// so just store them, don't store any nulls at all
// i first wrote the code using int in queue for the 2nd elt data type
// that gave overflow
// replaced it with long long int, still gave overflow
// so normalize the indices: subtract the smallest index from all indices at that level
// so overall effect is null 
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long int>> q;
        if(root==nullptr) return 0;
        q.push({root,0});

        long long int right=0;
        long long int left=0;

        long long int maxi=0;
        while(!q.empty()){
            int n=q.size();
            int minIdx=q.front().second;
            for(int i=0;i<n;i++){
                auto [node,idx]=q.front();
                q.pop();

                if(i==0) left=idx-minIdx;
                if(i==n-1) right=idx-minIdx;

                if(node->left) q.push({node->left,(idx-minIdx)*2+1});
                if(node->right) q.push({node->right,(idx-minIdx)*2+2}); 
            }
            maxi=max(maxi,right-left+1);
        }
        return (int)maxi;
    }
};
