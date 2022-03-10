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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode *odd=head, *even=head->next, *starte=head->next, *curr=head->next->next;
        int i=1;
        while(curr!=NULL){
            if(i%2==1){
                odd->next=curr;
                odd=odd->next;
            }
            else{
                even->next=curr;
                even=even->next;
            }
            curr=curr->next;
            i++;
        }
        odd->next=starte;
        even->next=NULL;
        return head;
    }
};