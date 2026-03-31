/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node* , Node*> mpp;

        Node* tmp = head;

        while(tmp){ 
            Node* newNode = new Node(tmp->val);
            mpp[tmp] = newNode;
            tmp = tmp -> next;
        }
        tmp = head;

        while(tmp){
            Node* copyNode = mpp[tmp];
            copyNode->next = mpp[tmp->next];
            copyNode->random = mpp[tmp->random];
            tmp = tmp->next;
        }
        return mpp[head];
    }
};
