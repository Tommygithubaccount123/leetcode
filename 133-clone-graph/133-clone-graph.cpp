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
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> storage;
        return helper(node, storage);
    }
    
    Node* helper(Node* node, unordered_map<Node*, Node*>& stor){
        if (!node){return nullptr;}
        
        if (stor.find(node)!=stor.end()){
            return stor[node];
        }
        
        Node* newNode = new Node(node->val);
        stor[node] = newNode;
        for (auto n : node->neighbors){
            newNode->neighbors.push_back(helper(n, stor));
        }
        
        return stor[node];
    }
    
};