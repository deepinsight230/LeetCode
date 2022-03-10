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
        ListNode *start=dummy, *end=dummy, *curr, *prev;
        int i=0;
        while(i<=right){
            if(i<left-1) start=start->next;
            end=end->next;
            i++;
        }
        curr=start->next->next;
        prev=start->next;
        while(curr!=end){
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        start->next->next=end;
        start->next=prev;
        return dummy->next;
    }
};