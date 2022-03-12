/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        Node *temp=head;
        while(temp){
            Node *next=temp->next;
            temp->next=new Node(temp->val);
            temp->next->next=next;
            temp=next;
        }
        temp=head;
        while(temp){
            temp->next->random=(temp->random)?(temp->random->next):NULL;
            temp=temp->next->next;
        }
        Node *head2=head->next;
        Node *ret=head->next;
        temp=head, temp->next=temp->next->next, temp=temp->next;
        while(temp){
            head2->next=temp->next;
            head2=head2->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return ret;
    }
};