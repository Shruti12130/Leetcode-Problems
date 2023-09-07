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
        ListNode* dummy=new ListNode(0), *temp;
        dummy->next=head;
        temp=dummy;
        
        for(int i=0;i<left-1;i++) {
            temp=temp->next;
        }
        ListNode* prev=temp, *curr=temp->next, *next;  
        
        for(int i=0;i<right-left;i++) {
            next=curr->next;
            curr->next=next->next;
            next->next=prev->next;
            prev->next=next;
        }
        
        return dummy->next;
    }
};