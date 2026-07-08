/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void solve(Node*& old,Node*& clone,unordered_map<Node*,Node*>& mp){
        for(Node* n:old->neighbors){
            if(mp.find(n)==mp.end()){
                Node* New=new Node(n->val);
                clone->neighbors.push_back(New);
                mp[n]=New;
                solve(n,New,mp);
            }
            else{
                clone->neighbors.push_back(mp[n]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        // making clone of given node
        if(!node) return nullptr;
        Node* clone=new Node(node->val);
        unordered_map<Node*,Node*> mp;
        mp[node]=clone;

        // make clone of its neighbours;
        solve(node,clone,mp);
        
        return clone;
    }
};