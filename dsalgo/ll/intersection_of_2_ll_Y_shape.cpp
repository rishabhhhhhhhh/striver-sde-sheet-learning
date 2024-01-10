Node * solve(Node * head1, int len1, Node * head2, int len2) {
    
    while(len1 > len2) {
        len1--;
        head1 = head1->next;
    }

    while(head1 != NULL && head2 != NULL && head1 != head2) {
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1;
}

int findLen(Node * head) {

    int ans = 0;
    while(head != NULL) {
        head = head->next;
        ans++;
    }
    return ans;
}

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    int len1 = findLen(firstHead);
    int len2 = findLen(secondHead);

    if(len1 > len2) {
        return solve(firstHead, len1, secondHead, len2);
    }
    return solve(secondHead, len2, firstHead, len1);
}
