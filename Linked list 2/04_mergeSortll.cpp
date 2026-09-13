// split at middle or it give middle element
Node* splitAtMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev != NULL){
        prev->next = NULL; // split at middle
    }

    return slow; // slow = rightHead
}

// In this part, merging two sorted list
Node* merge(Node* left, Node* right){ // two head (left , right)
    List ans;
    Node* i = left; // pointer or iterator for left list
    Node* j = right; // ptr or itr for right list
    
    while(i != NULL && j != NULL){
        if(i->data <= j->data){
            ans.push_back(i->data); // add ith data in ans list
            i = i->next; // update i
        } else {
            ans.push_back(j->data);
            j = j->next; // update j
        }
    }

    while(i != NULL){
        ans.push_back(i->data);
        i = i->next;
    }

    while(j != NULL){
        ans.push_back(j->data);
        j = j->next;
    }
    
    return ans.head;
}
Node* mergeSort(Node* head){
    // base case
    if(head == NULL || head->next == NULL){ 
        return head;
    }

    Node* rightHead = splitAtMid(head); // learn this first

    Node* left = mergeSort(head); //left head
    Node* right = mergeSort(rightHead); // right head

     return mergeSort(head, rightHead); //head of sorted list
}