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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        
        ListNode* temp=head;
        ListNode* odd=head, *even=head->next;
        ListNode* o=head, *e=head->next;
        
        while(o->next && e->next) {
            o->next=o->next->next;
            o=o->next;
            e->next=e->next->next;
            e=e->next;
        }
        o->next=even;
        return odd;
    }
};