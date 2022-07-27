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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy=new ListNode(0);
        ListNode *dhead=dummy;
        ListNode *curr1=list1, *curr2=list2;
        while(curr1 && curr2){
            if(curr1->val<=curr2->val){
                dhead->next=curr1;
                curr1=curr1->next;
            }
            else{
                dhead->next=curr2;
                curr2=curr2->next;
            }
            dhead=dhead->next;
        }
        while(curr1){
            dhead->next=curr1;
            curr1=curr1->next;
            dhead=dhead->next;
        }
        while(curr2){
            dhead->next=curr2;
            curr2=curr2->next;
            dhead=dhead->next;
        }
        ListNode *dnext=dummy->next;
        delete dummy;
        return dnext;
    }
};