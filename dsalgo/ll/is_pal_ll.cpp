LinkedListNode<int> * reverseList(LinkedListNode<int> * head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    LinkedListNode<int> * prev = NULL, *current = head, *nextPtr = head->next;
    while(current != NULL) {

        current->next = prev;

        prev = current;
        current = nextPtr;

        if(nextPtr != NULL) 
            nextPtr = nextPtr->next;
    }
    return prev;
}

bool isPal(LinkedListNode<int> * head1, LinkedListNode<int> * head2) {

    while(head1 != NULL && head2 != NULL && (head1->data == head2->data)) {
        head1 = head1->next;
        head2 = head2->next;
    }

    if(head1 == NULL || head2 == NULL)
        return true;
    return false;
}

bool isPalindrome(LinkedListNode<int> *head) {
    
    if(head == NULL || head->next == NULL)
        return true;

    LinkedListNode<int> *slowPtr = head, *fastPtr = head->next;

    while((fastPtr != NULL) && (fastPtr->next != NULL)) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    LinkedListNode<int> * secondListStart = slowPtr->next;
    slowPtr->next = NULL;

    secondListStart = reverseList(secondListStart);

    return isPal(head, secondListStart);
}