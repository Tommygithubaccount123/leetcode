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
    unordered_map<int,Node*> visited;
    
    Node* dfs(Node* node){
        if (!node){return nullptr;}
        if (visited.find(node->val) != visited.end()){return visited[node->val];}

        Node* copy = new Node(node->val);
        visited[node->val] = copy;
        for (auto n : node->neighbors){
            copy->neighbors.push_back(dfs(n));
        }
        return copy;
    }
    
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};