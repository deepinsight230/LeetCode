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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *curr=head;
        int n=1;
        while(curr->next){
            n++;
            curr=curr->next;
        }
        k=k%n;
        if(k==0) return head;
        ListNode *start=head, *end=head;
        int i=1;
        while(i<(n-k)){
            end=end->next;
            start=start->next;
            i++;
        }
        start=start->next;
        end->next=NULL;
        curr->next=head;
        return start;
    }
};