
int getsize(){
    int sz = 0;
    Node* temp = head;

    while(temp != NULL){
        temp = temp->next;
        sz++;
    }
    return sz;
}
void removeNth(int n){
    int size  = getsize();

    Node* prev = head;

    for(int i=1; i<(size-n); i++){
        prev = prev->next;
    }

    Node* toDel = prev->next;
    cout << "going to delete : " << toDel->data << endl;

    prev->next = prev->next->next;
}