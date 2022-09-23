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
    ListNode* reverseList(ListNode *head){
        ListNode *curr=head, *prev=NULL;
        while(curr){
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* first, ListNode* second) {
        ListNode *curr1=reverseList(first), *curr2=reverseList(second);
    ListNode *ans = new  ListNode(0);
    // ans->data=0;
    ListNode *anshead=ans;
    int carry=0, sum=0;
    while(curr1 && curr2){
        sum=curr1->val + curr2->val + carry;
        int rem=sum%10;
        carry=sum/10;
        ListNode *node=new ListNode();
        node->val = rem;
        anshead->next=node;
        anshead=anshead->next;
        curr1=curr1->next;
        curr2=curr2->next;
    }
    while(curr1){
        sum=curr1->val + carry;
        int rem=sum%10;
        carry=sum/10;
        ListNode *node=new ListNode();
        node->val = rem;
        anshead->next=node;
        anshead=anshead->next;
        curr1=curr1->next;
    }
    while(curr2){
        sum=curr2->val + carry;
        int rem=sum%10;
        carry=sum/10;
        ListNode *node=new ListNode();
        node->val = rem;
        anshead->next=node;
        anshead=anshead->next;
        curr2=curr2->next;
    }
    if(carry!=0){
        ListNode *node=new ListNode();
        node->val = carry;
        anshead->next=node;
        anshead=anshead->next;
    }
    ListNode *temp=ans;
    ans=ans->next;
    delete temp;
    
    return reverseList(ans);
    }
};