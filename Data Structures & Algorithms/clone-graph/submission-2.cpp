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
private:
    Node* dfs(Node* node , unordered_map<Node* , Node*>& oldToNew){
        if(node == nullptr){
            return nullptr;
        }

        if(oldToNew.find(node) != oldToNew.end()){
            return oldToNew[node];
        }

        Node* clone = new Node(node->val);
        oldToNew[node] = clone;

        for(auto& nei : node->neighbors){
            clone->neighbors.push_back(dfs(nei , oldToNew));
        }

        return clone ;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node* , Node*> oldToNew;
        return dfs(node , oldToNew);
    }
};
