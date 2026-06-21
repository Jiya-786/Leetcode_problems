/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// USING BFS
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root==nullptr) return root;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* node1=q.front();
                q.pop();
                if(i==n-1){
                     node1->next=nullptr;
                }
                else{
                    node1->next=q.front();
                }
                if(node1->left) q.push(node1->left);
                if(node1->right) q.push(node1->right);
            }
        }
        return root;
    }
};