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
    pair<ListNode *, int> reverse(ListNode *head){
        ListNode *curr=head, *prev=NULL;
        int i=0;
        while(curr){
            i++;
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return {prev, i};
    }
    int pairSum(ListNode* head) {
        ListNode *curr=head, *h=new ListNode(), *h2=h;
        while(curr){
            ListNode *node=new ListNode(curr->val);
            h->next=node;
            h=h->next;
            curr=curr->next;
        }
        pair<ListNode *, int> ans=reverse(h2->next);
        ListNode *head2=ans.first;
        int n=ans.second;
        int mx=INT_MIN;
        for(int i=0;i<(n/2);i++){
            mx=max(mx, head->val+head2->val);
            head=head->next;
            head2=head2->next;
        }
        return mx;
    }
};