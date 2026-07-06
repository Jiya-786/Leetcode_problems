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
// // class Solution {
// // public:
// //     TreeNode* sortedArrayToBST(vector<int>& nums) {
// //         if(nums.empty()) return root;

// //         int mid=nums.size()/2;
// //         TreeNode* root=new TreeNode(nums[mid]);      // the rhs returns a pointer to the new node
// //         root->left=sortedArrayToBST(nums.begin(),nums.begin()+mid);
// //         root->right=sortedArrayToBST(nums.begin()+mid+1,nums.end());
// //         return root;
// //     }
// // };

// // the previous method created many new arrays for each call
// // instead we can just pass indices to avoid space and time overhead
// // time o(n)
// // space o(logn) for recursion stack
// // sapce o(n) for output
// class Solution {
// public:
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         if(nums.empty()) return nullptr;
//         return build(nums,0,nums.size()-1);       
//     }
// private:
//     TreeNode* build(vector<int>&nums,int l,int r){
//         if(l>r) return nullptr;         // this is imp line
//         int mid=l+((r-l)/2);
//         TreeNode* node=new TreeNode(nums[mid]);
//         node->left=build(nums,l,mid-1);
//         node->right=build(nums,mid+1,r);

//         return node;
//     }
// };

// ITERATIVE DFS using stack
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
          if(nums.empty()) return nullptr;

          TreeNode* root=new TreeNode(0);
          stack<tuple<TreeNode*,int,int>> st;
          st.push({root,0,nums.size()-1});

          while(!st.empty()){
            auto [node,l,r]=st.top();
            st.pop();
            int mid=l+(r-l)/2;
            node->val=nums[mid];

            if(l<=mid-1){
                node->left=new TreeNode(0);  // no need of TreeNode* node->left=new TreeNode(0); since 
                                                       // node->left and right are already defined beforehand in qs
                                                       // definition
                st.push({node->left,l,mid-1});
            }
            if(mid+1<=r){
                node->right=new TreeNode(0);
                st.push({node->right,mid+1,r});
            }
          }
          return root;
    }
};