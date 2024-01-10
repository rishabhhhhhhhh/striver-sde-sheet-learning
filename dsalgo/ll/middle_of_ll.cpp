Node *findMiddle(Node *head) {
    Node * slowPtr = head;
    Node * fastPtr = head;

    while((fastPtr != NULL) && (fastPtr->next != NULL)) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    return slowPtr;
}

