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
    ListNode *middle(ListNode *head){
        ListNode *slow=head, *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode *mergeSort(ListNode *head1, ListNode *head2){
        ListNode *merged=new ListNode(0);
        ListNode *mhead=merged;
        ListNode *curr1=head1, *curr2=head2;
        while(curr1 && curr2){
            if(curr1->val<curr2->val) merged->next=curr1, curr1=curr1->next;
            else merged->next=curr2, curr2=curr2->next;
            merged=merged->next;
        }
        if(curr1) merged->next=curr1;
        if(curr2) merged->next=curr2;
        ListNode *dhead=mhead->next;
        delete mhead;
        return dhead;
    }
    ListNode *merge(ListNode *head){
        if(head==NULL || head->next==NULL) return head;
        ListNode *mid=middle(head);
        ListNode *nhead=mid->next;
        mid->next=NULL;
        ListNode *fsh=merge(head);
        ListNode *ssh=merge(nhead);
        ListNode *sfull=mergeSort(fsh, ssh);
        return sfull;
    }
    ListNode* sortList(ListNode* head) {
        ListNode *ans=merge(head);
        return ans;
    }
};