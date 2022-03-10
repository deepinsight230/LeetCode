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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr1=l1, *curr2=l2;
        ListNode *head=new ListNode(), *curr=head;
        int carry=0;
        while(curr1&&curr2){
            int sum=curr1->val+curr2->val+carry;
            int plus=sum%10;
            carry=sum/10;
            ListNode *node=new ListNode(plus);
            curr->next=node;
            curr=curr->next;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        while(curr1){
            int sum=curr1->val+carry;
            int plus=sum%10;
            carry=sum/10;
            ListNode *node=new ListNode(plus);
            curr->next=node;
            curr=curr->next;
            curr1=curr1->next;
        }
        while(curr2){
            int sum=curr2->val+carry;
            int plus=sum%10;
            carry=sum/10;
            ListNode *node=new ListNode(plus);
            curr->next=node;
            curr=curr->next;
            curr2=curr2->next;
        }
        if(carry!=0){
            ListNode *node=new ListNode(carry);
            curr->next=node;
        }
        return head->next;
    }
};