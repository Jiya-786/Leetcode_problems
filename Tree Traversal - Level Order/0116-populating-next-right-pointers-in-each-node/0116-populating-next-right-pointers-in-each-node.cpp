// /*
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;
//     Node* next;

//     Node() : val(0), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val, Node* _left, Node* _right, Node* _next)
//         : val(_val), left(_left), right(_right), next(_next) {}
// };
// */

// // USING BFS
// this is o(n) space soln, qs requires o(1) space solution
// class Solution {
// public:
//     Node* connect(Node* root) {
//         queue<Node*> q;
//         if(root==nullptr) return root;
//         q.push(root);

//         while(!q.empty()){
//             int n=q.size();
//             for(int i=0;i<n;i++){
//                 Node* node1=q.front();
//                 q.pop();
//                 if(i==n-1){
//                      node1->next=nullptr;
//                 }
//                 else{
//                     node1->next=q.front();
//                 }
//                 if(node1->left) q.push(node1->left);
//                 if(node1->right) q.push(node1->right);
//             }
//         }
//         return root;
//     }
// };

// now doing it in constant o(1) space
// in the qs we are given left and right child pointer for each node
// and also given that the tree is a perfect binary tree
// implies each node has both left and right children
class Solution {
public:
    Node* connect(Node* root) {
        Node* lvlStart=root;
        if(!root) return root;

        while(lvlStart->left){
            Node* node=lvlStart;

            while(node){
                node->left->next=node->right;   // it's a perfect binary tree, hence left and right child 
                                                // always exist except in case of leaf nodes

                if(node->next){
                    node->right->next=node->next->left;
                }

                node=node->next;
            }
            lvlStart=lvlStart->left;
        }
        return root;
    }
};
