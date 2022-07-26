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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        ListNode *dummy=new ListNode(0, head);
        ListNode *slow=dummy;
        while(fast){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode *next=slow->next;
        slow->next=next->next;
        delete next;
        ListNode *temp=dummy->next;
        delete dummy;
        return temp;
    }
};