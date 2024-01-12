//delete node whose reference is given (not head or tail node)
//https://www.codingninjas.com/studio/problems/1105578?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
void deleteNode(LinkedListNode<int> * node) {
    LinkedListNode<int> * nextNode = node->next;
    node->data = nextNode->data;
    node->next = nextNode->next;
    delete nextNode;
}