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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode *connect=new ListNode(0);
        ListNode *dummy=new ListNode(0);
        ListNode *connectH=connect;
        dummy->next=head;
        ListNode *curr=dummy;
        while(curr->next){
            ListNode *next=curr->next;
            if(next->val<x){
                curr=curr->next;
            }
            else{
                curr->next=next->next;
                next->next=NULL;
                connect->next=next;
                connect=connect->next;
            }
        }
        curr->next=connectH->next;
        return dummy->next;
    }
};