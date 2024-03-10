class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *tail = NULL;
        int carry = 0, sum = 0;
        while(l1 != NULL && l2 != NULL) {
            sum = (l1->val) + (l2->val) + carry;
            carry = sum/10;
            sum = sum%10;
            ListNode * node = new ListNode(sum, NULL);
            if(head == NULL) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL) {
            sum = (l1->val) + carry;
            carry = sum/10;
            sum = sum%10;
            ListNode * node = new ListNode(sum, NULL);
            if(head == NULL) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
            l1 = l1->next;
        }
        while(l2 != NULL) {
            sum = (l2->val) + carry;
            carry = sum/10;
            sum = sum%10;
            ListNode * node = new ListNode(sum, NULL);
            if(head == NULL) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
            l2 = l2->next;
        }
        if(carry > 0) {
            ListNode * node = new ListNode(carry, NULL);
            if(head == NULL) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }
        return head;
    }
};