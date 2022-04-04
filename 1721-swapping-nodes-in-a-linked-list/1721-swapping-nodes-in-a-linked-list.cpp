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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *slow=head, *fast=head, *curr=head;
        int i=1;
        while(i<=k){
            curr=curr->next;
            i++;
        }
        i=1;
        while(curr||i<k){
            if(curr){
                fast=fast->next;  
                curr=curr->next;
            }
            if(i<k) slow=slow->next, i++;
        }
        swap(slow->val, fast->val);
        return head;
    }
};