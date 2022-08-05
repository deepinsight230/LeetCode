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
    struct myComp{
        bool operator()(ListNode* head1, ListNode *head2){
            return head1->val>head2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, myComp> pq;
        for(auto head: lists) if(head) pq.push(head);
        ListNode *dummy=new ListNode(0);
        ListNode *curr=dummy;
        while(!pq.empty()){
            ListNode *head=pq.top();
            pq.pop();
            curr->next=head;
            curr=curr->next;
            head=head->next;
            if(head) pq.push(head);
        }
        ListNode *temp=dummy->next;
        delete dummy;
        return temp;
    }
};