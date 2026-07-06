// // // RECURSIVE
// // class Solution {
// // public:
// //     vector<int> inorderTraversal(TreeNode* root) {
// //         vector<int> result;
// //         inorder(root,result);
// //         return result;
// //     }
// // private:
// //     void inorder(TreeNode* node,vector<int>& result){
// //         if(node==nullptr) return;

// //         inorder(node->left,result);
// //         result.push_back(node->val);
// //         inorder(node->right,result);
// //     }
// // };

// // ITERATIVE
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         stack<TreeNode*> st;
//         vector<int> result;
//         TreeNode* curr=root;

//         while(curr||!st.empty()){
//             while(curr){
//                 st.push(curr);
//                 curr=curr->left;
//             }
//             curr=st.top();
//             st.pop();
//             result.push_back(curr->val);

//             curr=curr->right;
//         }
//         return result;
//     }
// };

// MORRIS TRAVERSAL
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr=root;

        while(curr!=nullptr){
            if(curr->left==nullptr){
                result.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* req=curr->left;
                while(req->right!=nullptr && req->right!=curr){
                    req=req->right;
                }
                if(req->right==nullptr){  // this would be our first visit
                    req->right=curr;   // create thread
                    
                    curr=curr->left;
                }
                else{         // this would be our 2nd visit
                    req->right=nullptr;   // break the thread;
                    result.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return result;
    }
};
