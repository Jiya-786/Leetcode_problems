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

// // BFS method, using queue
// // ir o(n) extra space
// // but qs mention constant extra space
// // hence we need to make use of already established next pointers
// class Solution {
// public:
//     Node* connect(Node* root) {
//         queue<Node*> q;
//         if(!root) return nullptr;

//         q.push(root);

//         while(!q.empty()){
//             int n=q.size();
//             for(int i=0;i<n;i++){
//                 Node* node=q.front();
//                 q.pop();

//                 if(i!=n-1){
//                     node->next=q.front();
//                 }

//                 if(node->left) q.push(node->left);
//                 if(node->right) q.push(node->right);
//             }
//         }
//         return root;
//     }
// };

// BFS IN CONSTANT SPACE USING ALREADY ESTABLISHED NEXT POINTERS
// the code seems confusing at first since we are using the same pointer curr in 2 diff ways
// 1st for traversing through diff levels top to bottom
// and 2nd for traversing across levels, left to right
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;

        Node* curr=root;

        while(curr){
            Node dummy(0);             //   dummy
            Node* tail=&dummy;         //   tail^

            while(curr){
                if(curr->left){             //     dummy ->    2
                    tail->next=curr->left;  //             tail^
                    tail=tail->next; 
               }
               if(curr->right){             //     dummy -> 2 ->   3
                tail->next=curr->right;     //                  tail^
                tail=tail->next;
               }
               curr=curr->next;             
            } 
            curr=dummy.next; // move down to next level       curr=2
        }                    // now repeat the whole cycle for 2 just like we did for root
        return root;
    }
};