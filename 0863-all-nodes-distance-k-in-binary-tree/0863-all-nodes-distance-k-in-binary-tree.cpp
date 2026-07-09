/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // we need to count no.of edges. whenever=k,return those nodes
 // its simpler using bfs becuase we can track each level
 // all nodes of a given level will have same no.of edges from target node
 // but onw problem is we can only go left and right using given info
 // we should also be able to go up the parent
 // so we need to store parent data like left and right
class Solution {
public:
    void solveParents(TreeNode* node,unordered_map<int,TreeNode*>& parentsVec){
        if(node==nullptr) return;
        TreeNode* d=node;
        if(node->left){
            parentsVec[node->left->val]=d;
            solveParents(node->left,parentsVec);
        }
        if(node->right){
            parentsVec[node->right->val]=d;
            solveParents(node->right,parentsVec);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,TreeNode*> parentsVec;
        // first doing pre-order traversal and assigning parents
        solveParents(root,parentsVec);
        queue<TreeNode*> q;
        vector<int> result;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target); 
        while(!q.empty()){
            if(k!=0){
                int n=q.size();
                while(n--){
                    TreeNode* a=q.front();
                    q.pop();

                    // rember to use a visited array else gets stuck in infinte loop
                    if(a->left && visited.find(a->left)==visited.end()) q.push(a->left);
                    if(a->right && visited.find(a->right)==visited.end()) q.push(a->right);
                    if(parentsVec[a->val] && visited.find(parentsVec[a->val])==visited.end()) q.push(parentsVec[a->val]);

                    visited.insert(a);
                    // k--;   this is not in the correct loop
            }
            k--; 
            } 
            if(k==0){
                for(int i=0;i<q.size();i++){
                TreeNode* a=q.front();
                q.pop();
                result.push_back(a->val);
                }
            }
        }
        return result;
    }   
};      