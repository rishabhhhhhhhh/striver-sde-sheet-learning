LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head == NULL) {
        return NULL;
    }

    LinkedListNode<int> *current = head, *prev = NULL, *nextPtr = head->next;

    while(current != NULL) {

        current->next = prev;

        prev = current;
        
        current = nextPtr;

        if (nextPtr != NULL) {
          nextPtr = nextPtr->next;
        }
    }

    return prev;
}