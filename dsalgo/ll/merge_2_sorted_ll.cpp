ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;
    ListNode *prev = NULL, *head = NULL;
    while(list1 != NULL && list2 != NULL) {
        if(list1->val <= list2->val) {
            if(head == NULL)
                head = list1;
            else
                prev->next = list1;
            prev = list1;
            list1 = list1->next;
        } else {
            if(head == NULL)
                head = list2;
            else
                prev->next = list2;
            prev = list2;
            list2 = list2->next;
        }
    }
    if(list1 == NULL)
        prev->next = list2;
    else
        prev->next = list1;
    return head;
}