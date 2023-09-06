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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        int len=0;
        ListNode* temp=head;
        while(temp) {
            temp=temp->next;
            len++;
        }
        temp=head;
        int i=0;
        if(len < k) {
            int x=k-len;
            while(len--) {
                ListNode* t=temp;
                ans[i++]=t;
                temp=temp->next;
                t->next=NULL;
            }
            while(x--) {
                ans[i++]=NULL;
            }
        } else {
            //x is the min length of the lists
            int x=len/k, r=len%k;
            int p=x+r;
            while(k--) {
                ans[i++]=temp;
                ListNode* t=temp;
                int m=x-1;
                while(m--) {
                    t=t->next;
                }
                if(r) {
                    t=t->next;
                    r--;
                }
                temp=t->next;
                t->next=NULL;
            }
        }
        return ans;
    }
};