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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy=new ListNode(-100000, head);
        ListNode *curr=head->next, *prev=head;
        while(curr){
            ListNode *move=dummy;
            while(move!=curr && move->next->val<=curr->val) move=move->next;
            if(move==curr){
                curr=curr->next;
                prev=prev->next;
                continue;
            }
            ListNode *mnext=move->next, *cnext=curr->next;
            move->next=curr;
            curr->next=mnext;
            prev->next=cnext;
            curr=cnext;
        }
        return dummy->next;
    }
};