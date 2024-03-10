class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
            return head;
        ListNode * fast = head;
        for(int i=1;i<n;i++)
            fast=fast->next;
            
        ListNode * prev = NULL, *newHead = head;
        while(fast->next!=NULL){
            fast=fast->next;
            prev = head;
            head=head->next;
        }
        if(prev == NULL) {
            prev = head;
            newHead = head->next;
            delete prev;
        } else {
            prev->next = head->next;
            delete head;
        }
        return newHead;
    }
};