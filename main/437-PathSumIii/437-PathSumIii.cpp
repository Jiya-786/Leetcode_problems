// Last updated: 30/06/2026, 19:33:03
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

// // optimized soln
// // exactly similar to subarray sum equals k
// //  subarray is contiguos part of array
// // and sum of any subarray from index j to i is prefixSum[i]-prefixSum[j-1]
// // so say target sum=k
// // then if we maintain a prefixSum map and use k=prefixSum[i]-prefixSum[j-1]-
// // ie prefixSum[j-1]=prefixSum[i]-k
// // we only need to search in the past prefix sums we have accumulated becuase j is our left pointer(not literally, just context wise) and i is the current position we are at pointer, so if we are at i we will have already accumulated past prefix sums and we can check if our target sum is possible to be built or not 
// // nice clean simple
// class Solution {
// public:
//     int pathSum(TreeNode* root, int targetSum) {
//         unordered_map<long long,int> prefixMap;
//         prefixMap[0]=1;

//         return dfs(root,0LL,targetSum,prefixMap);
//     }
//     int dfs(TreeNode* node,lon long currSum,int targetSum,unordered_map<long,long,int>& prefixMap){
//         if(!node) return 0;

//         currentSum+=node->val;

//         int count=prefixMap[currentSum-targetSum];

//         prefixMap[currSum]++;

//         count+=dfs(node->left,currSum,targetSum,prefixMap);
//         count+=dfs(node->right,currSum,targetSum,prefixMap);

//         prefixMap[currSum]--;

//         return count;
//     }
// };

// BRUTE FORCE
// dfs from every node
// we need 2 layers
// one outer layer for seleting node
// 2nd inner layer for doing dfs from that selected node
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
       if(!root) return 0;

       // count paths starting from this node and every otehr node in its left and right subtree
       return countFromNode(root,targetSum,0)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }

    int countFromNode(TreeNode* node, int targetSum, long long currentSum) {
        if(!node) return 0;

        currentSum+=node->val;
        int count=0;

        if(currentSum==targetSum) count++;

        count+=countFromNode(node->left,targetSum,currentSum);
        count+=countFromNode(node->right,targetSum,currentSum);

        return count;
    }
};