void removeCycle(Node* head){
    // detect cycle
    Node* slow = head;
    Node* fast = head;

    bool isCycle = false;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next; // +1
        fast = fast->next->next; // +2

        if(slow == fast){
            cout << "cycle exist\n";
            isCycle = true;
           break;
        }
    }

    if(!isCycle){
        cout << "cycle doesn't exist\n";
        return;
    }

    slow = head;
    if(slow == fast){ // special case : tail -> head

        while(fast->next != slow){
            fast = fast->next;
        }
        fast->next = NULL; // remove cycle
    } else {
        Node* prev = fast;
        while(slow != fast){
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL; // remove cycle
    }
}