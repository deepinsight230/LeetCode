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
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *st=dummy, *end=dummy;
        for(int i=1;i<left;i++){
            st=st->next;
        }
        int revcnt= right-left +1;
        ListNode *curr=st->next, *prev=st;
        while(revcnt>0){
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            revcnt--;
        }
        st->next->next=curr;
        st->next=prev;
        return dummy->next;
    }
};