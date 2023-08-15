/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=head;
        ListNode* smaller=new ListNode(-1), *larger=new ListNode(0);
        ListNode* s=smaller, *l=larger;
        
        while(temp) {
            if(temp->val < x) {
                s->next = new ListNode(temp->val);
                s=s->next;
            } else {
                l->next = new ListNode(temp->val);
                l=l->next;
            }
            temp=temp->next;
        }
        s->next=larger->next;
        return smaller->next;
    }
};