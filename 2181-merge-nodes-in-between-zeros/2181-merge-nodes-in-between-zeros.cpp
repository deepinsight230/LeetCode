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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *curr=head->next, *prev=head;
        int sum=0;
        while(curr){
            sum=0;
            ListNode *next=curr;
            while(curr->val!=0){
                sum+=curr->val;
                curr=curr->next;
            }
            prev->val=sum;
            prev->next=curr;
            if(curr->next) prev=curr;
            curr=curr->next;
            delete next;
        }
        prev->next=NULL;
        return head;
    }
};