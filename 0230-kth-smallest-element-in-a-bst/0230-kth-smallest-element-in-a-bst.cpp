// // /**
// //  * Definition for a binary tree node.
// //  * struct TreeNode {
// //  *     int val;
// //  *     TreeNode *left;
// //  *     TreeNode *right;
// //  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// //  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// //  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// //  * };
// //  */

// RECURSIVE INORDER
// // class Solution {
// // public:
// //     int kthSmallest(TreeNode* root, int k) {
// //         vector<int> result;
// //         inorder(root,result);

// //         return result[k-1];
// //     }
// // private:
// //     void inorder(TreeNode* node,vector<int>& result){
// //         if(!node) return;

// //         inorder(node->left,result);
// //         result.push_back(node->val);
// //         inorder(node->right,result);
// //     }
// // };

// RECURSIVE INORDER WITH SPACE OPTIMIZATION
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         int res=0;
//         int count=0;
//         inorder(root,k,res,count);

//         return res;
//     }
// private:
//     void inorder(TreeNode* node,int k,int& res,int& count){      // we have to pass res and k 
//                                                                            // as parameteres here becuase it is better we keep inorder function as void return type only, ow if we put int return type, it will get complicated since it is recursion, what would you return everytime? hence this is the best way out 
//         if(!node) return;

//         inorder(node->left,k,res,count);
//         // int count=0;
//         // count++;          // count should also be passed as a paramaeter cuz ow,
//                              // it will be recreated from 0 for every function call
//         count++;
//         if(count==k){
//             res=node->val;
//             return;
//         }

//         inorder(node->right,k,res,count);
//     }
// };

// ITERATIVE INORDER
// An iterative in-order traversal produces the same ascending visit order as the recursive version, with one advantage: when the kth node is reached, the function returns directly out of the loop. No ancestor frames resume, so no node past the kth is ever visited.
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr=root;

        while(curr||!st.empty()){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            k--;
            if(k==0) return curr->val;

            curr=curr->right;
        }
        return -1;
    }
};