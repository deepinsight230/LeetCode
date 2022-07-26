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
    ListNode *ahead(ListNode *head, int k){
        ListNode *fast=head;
        for(int i=0;i<k;i++) fast=fast->next;
        ListNode *dummy=new ListNode(0, head);
        ListNode *slow=head;
        while(fast){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode *prev(ListNode *head, int k){
        ListNode *curr=head;
        for(int i=1;i<k;i++) curr=curr->next;
        return curr;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *second=ahead(head, k);
        ListNode *first=prev(head, k);
        swap(first->val, second->val);
        return head;
    }
};