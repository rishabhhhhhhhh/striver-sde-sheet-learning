//delete node whose reference is given (not head or tail node)
void deleteNode(LinkedListNode<int> * node) {
    LinkedListNode<int> * nextNode = node->next;
    node->data = nextNode->data;
    node->next = nextNode->next;
    delete nextNode;
}