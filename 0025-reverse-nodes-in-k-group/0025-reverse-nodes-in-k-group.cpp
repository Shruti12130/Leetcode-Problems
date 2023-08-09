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
    ListNode* reverse(ListNode* first, ListNode* last) {
        //This function would make the head point to the (k+1)th node
        //followed by the reversed LL of group of size k
        //For LL 1->2->3->4-> and k=3, f=1, l=4
        //This fn will return 4->3->->2->1
        
        ListNode* prev = last;
        
        while(first != last) {
            ListNode* temp = first->next;
            first->next = prev;
            prev = first;
            first = temp;
        }
        return prev;
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        //Iterate k times to find kth node. temp would point to (k+1)th node in the end.
        for(int i=0; i<k; i++) {
            if(!temp){    //this group does not contain k nodes
                return head;
            }
            temp = temp->next;
        }
        //temp is pointing to (k+1)th node or the first node of next group
        //first = 0th node   last = (k+1)th node
        ListNode* headOfReversedGroup = reverse(head, temp);
        head->next = reverseKGroup(temp, k);
        return headOfReversedGroup;
    }
};