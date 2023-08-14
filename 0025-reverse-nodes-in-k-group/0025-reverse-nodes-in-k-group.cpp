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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        //Iterate k times to find kth node. temp would point to (k+1)th node in the end.
        for(int i=0;i<k;i++) {
            if(!curr){    //this group does not contain k nodes
                return head;
            }
            curr=curr->next;
        }
        
        curr=head;
        ListNode* prev=NULL, *next;
        
        for(int i=0;i<k;i++) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};