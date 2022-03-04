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
        if(head==NULL) return head;
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *curr=dummy->next, *prev=dummy;
        bool flag=true;
        while(curr->next!=NULL){
            if(curr->next->val==curr->val){
                ListNode *next=curr->next;
                curr->next=next->next;
                delete next;
                flag=false;
            }
            else{
                if(flag==false){
                    curr=curr->next;
                    ListNode *next=prev->next;
                    delete next;
                    prev->next=curr;
                    flag=true;
                }
                else{
                    prev=curr;
                    curr=curr->next;
                }
            }
        }
        if(flag==false){
            curr=curr->next;
            ListNode *next=prev->next;
            delete next;
            prev->next=curr;
        }
        return dummy->next;
    }
};