void reverse(){
    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL){
        Node* next = curr->next;
        curr->next = prev;

        // updations for next itr
        prev = curr;
        curr = next;
    }

    head = prev;
}