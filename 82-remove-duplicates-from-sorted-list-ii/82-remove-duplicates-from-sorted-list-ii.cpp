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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *curr=head, *prev=dummy;
        bool repeat=false;
        while(curr!=NULL){
            while(curr&&curr->next&&curr->val==curr->next->val){
                curr=curr->next;
                repeat=true;
            }
            if(prev->next->val==curr->val&&repeat){
                ListNode *next=prev->next;
                curr=curr->next;
                prev->next=curr;
                repeat=false;
                delete next;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return dummy->next;
    }
};