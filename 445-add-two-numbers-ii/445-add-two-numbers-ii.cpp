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
    ListNode* reverse(ListNode *head){
        ListNode *curr=head, *prev=NULL;
        while(curr){
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        int carry=0, plus, sum;
        ListNode *curr1=l1, *curr2=l2, *ret=new ListNode(), *curr=ret;
        while(curr1&&curr2){
            sum=curr1->val+curr2->val+carry;
            plus=sum%10;
            carry=sum/10;
            ListNode *node=new ListNode(plus);
            curr->next=node;
            curr=curr->next;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        while(curr1){
            sum=curr1->val+carry;
            plus=sum%10;
            carry=sum/10;
            ListNode *node=new ListNode(plus);
            curr->next=node;
            curr=curr->next;
            curr1=curr1->next;
        }
        while(curr2){
            sum=curr2->val+carry;
            plus=sum%10;
            carry=sum/10;
            ListNode *node=new ListNode(plus);
            curr->next=node;
            curr=curr->next;
            curr2=curr2->next;
        }
        if(carry!=0){
            ListNode *node=new ListNode(carry);
            curr->next=node;
            curr=curr->next;
        }
        ret=reverse(ret->next);
        return ret;
    }
};