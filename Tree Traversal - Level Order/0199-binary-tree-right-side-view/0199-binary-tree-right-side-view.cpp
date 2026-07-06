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
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> result;
//         if(root==nullptr) return result;

//         queue<TreeNode*> q;
//         q.push(root);

//         while(!q.empty()){
//             int levelSize=q.size();

//             for(int i=0;i<levelSize;i++){
//                 TreeNode* node=q.front();
//                 q.pop();

//                 // the last node is the right side view
//                 if(i==0){
//                     result.push_back(node->val);
//                 }

//                 // this is just a slight variation of the first submission, instead of processing left-to-right and pushing the rightmost ie last elt into result, we process right to left and push the first node into result
//                 if(node->right) q.push(node->right);    // note: not result.push_back() or q.push_back()
//                 if(node->left) q.push(node->left);      // 
                
//                 // if(node->right) q.push(node->right);  
//             }        
//         }
//         return result;

//     }
// };

//   If we do a depth-first traversal where we go right before left, then the first node we encounter at each new depth level is guaranteed to be the rightmost node at that level.

// The trick is knowing when we have reached a "new" depth.

//  If depth == result.size(), we have not recorded any node at this depth yet, so the current node is the first (rightmost) one we have seen at this level.

// This is elegant because it flips the perspective. Instead of scanning each level and keeping the last node, we visit in an order that naturally hits the rightmost node first.

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root,0,result);
        return result;
    }
private:
    void dfs(TreeNode* node, int level, vector<int>& result){
        if(node==nullptr){
            return;
        }
        // first node at a given depth is rightmost since that is how we are processing it
        if(level==result.size()){
            result.push_back(node->val);
        }

        dfs(node->right,level+1,result);
        dfs(node->left,level+1,result);

    }

    
};