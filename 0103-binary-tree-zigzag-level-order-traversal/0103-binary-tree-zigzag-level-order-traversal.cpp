// // // using bfs and reversing when req
// // class Solution {
// // public:
// //     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
// //         vector<vector<int>> result;
// //         queue<TreeNode*> q;
// //         if(root==nullptr) return result;
// //         int lvl=0;

// //         q.push(root);

// //         while(!q.empty()){
// //             int n=q.size();
// //             vector<int> currentLevel;
// //             for(int i=0;i<n;i++){
// //                 TreeNode* node=q.front();
// //                 q.pop();

// //                 currentLevel.push_back(node->val);

// //                 if(node->left) q.push(node->left);
// //                 if(node->right) q.push(node->right);
                
// //             }
// //             if(lvl%2!=0){ reverse(currentLevel.begin(),currentLevel.end());
// //             }

// //             result.push_back(currentLevel);
// //             lvl++;


// //         } 
// //         return result;
// //     }
// // };

// // using deque iewith BFS
// // at one lvl add all child nodes to the back
// // at next lvl add all child nodes to the front
// // so when we process nodes from the front, it will give us right->left traversal
// // 
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         queue<TreeNode*> q;
//         vector<vector<int>> result;
//         if(root == nullptr) return {};
//         q.push(root);
//         int lvl=0;

//         while(!q.empty()){
//             int n=q.size();
//             deque<int> currentLevel;

//             for(int i=0;i<n;i++){
//                 TreeNode* node=q.front();
//                 q.pop();

//                 if(lvl%2!=0){
//                     currentLevel.push_front(node->val);
//                 }
//                 else{
//                     currentLevel.push_back(node->val);
//                 }
//                 if(node->left) q.push(node->left);
//                 if(node->right) q.push(node->right);
//             }
//             result.push_back(vector<int>(currentLevel.begin(),currentLevel.end()));
//             lvl++;
//         }
//         return result;
//     }
// };

// USING DFS WITH LEVEL TRACKING
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<deque<int>> v;
        dfs(root,0,v);

        vector<vector<int>> result;
        for(auto& it:v){
            result.push_back(vector<int>(it.begin(),it.end()));
        }
        return result;
    }
private:
    void dfs(TreeNode* node, int level, vector<deque<int>>& v){
        if(node==nullptr) return;

        if(level==v.size()){
            v.push_back({});
        }

        if(level%2==0){
            v[level].push_back(node->val);
        }
        else{
            v[level].push_front(node->val);
        }

        dfs(node->left,level+1,v);
        dfs(node->right,level+1,v);
    }
};