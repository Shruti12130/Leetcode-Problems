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
        if(!head) {
            return head;
        }
        unordered_map<Node*, Node*> mp;
        Node* newHead = new Node(-1);
        Node* temp=head, *t=newHead;
        while(temp) {
            t->next = new Node(temp->val);
            mp[temp]=t->next;
            t=t->next;
            temp=temp->next;
        }
        temp=head, t=newHead;
        while(temp) {
            t->next->random = mp[temp->random];
            t=t->next;
            temp=temp->next;
        }
        return newHead->next;
    }
};