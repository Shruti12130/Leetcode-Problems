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
    unordered_map<Node*, Node*> mp;
    
    Node* cloneGraph(Node* node) {
        if(!node) {
            return NULL;
        }
        
        Node* clonedGraph = new Node(node->val);
        mp[node] = clonedGraph;
        for(auto it: node->neighbors) {
            if(mp.count(it)) {
                clonedGraph->neighbors.push_back(mp[it]);
            } else {
                clonedGraph->neighbors.push_back(cloneGraph(it));
            }
        }
        return clonedGraph;
    }
};