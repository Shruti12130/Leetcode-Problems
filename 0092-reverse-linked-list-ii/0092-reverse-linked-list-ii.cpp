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
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) {
            return head;
        }
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* last=dummy, *curr=head;
        int c=1;
        while(c<left){
            last=curr;
            curr=curr->next;
            c++;
        }
        ListNode* prev=NULL, *next=NULL;
        while(c<right){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            c++;
        }
        last->next->next=curr->next;
        curr->next=prev;
        last->next=curr;
        return dummy->next;
    }
};