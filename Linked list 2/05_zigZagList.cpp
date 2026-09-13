
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev; // prev is head of reversed LL

    // alternate merging : 1st head = head; 2nd head = rightHeadRev
}


void zigZagLL(Node* head){
    Node* rightHead = splitAtMid(head);
    Node* rightHeadRev = reverse(rightHead);
}
Node* zigZagList(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

    }

    if(prev != NULL){
        prev->next = NULL; // split at middle
    }

    return slow;
}