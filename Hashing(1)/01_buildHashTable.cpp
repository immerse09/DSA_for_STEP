#include<iostream>
#include<vector>
using namespace std;

// this class represents make node at each index
class Node {
    public:
    string key;
    int val;
    Node* next;

    Node(string key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
    }

    // destructor for delete
    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

// class for hashtable
class hashTable {
    int totSize;
    int currSize;
    Node** table;

    // hash function
    int hashFunction(string key){
        int idx = 0;

        for(int i=0; i<key.size(); i++){
            idx = idx + (key[i] * key[i])%totSize;
        }

        return idx;
    }

    // rehashing func.
    void rehash(){ // so O(n) + O(n) = O(n)
        Node** oldTable = table;
        int oldSize = totSize;

        totSize = 2*totSize;
        table = new Node*[totSize];

        for(int i=0; i<totSize; i++){ //O(n)
            table[i] = NULL;
        }

        // copy old table in new 
        for(int i=0; i<oldSize; i++){ //O(n)
            Node* temp = oldTable[i];
            while(temp != NULL){
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            // delete
            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        }

        delete[] oldTable;
    }

    public:
    hashTable(int size){
        totSize = size;
        currSize = 0;
        table = new Node*[totSize];

        for(int i=0; i<totSize; i++){
            table[i] = NULL;
         }
    }



// 3 func. of hashtable ----------

    void insert(string key, int val){ //O(1) avg
        int idx = hashFunction(key);

        Node* newNode = new Node(key, val);

        newNode->next = table[idx];
        table[idx] = newNode;
       

        currSize++;

        double lambda = currSize/(double)totSize;
        if(lambda > 1){
            rehash(); //O(n) - worst
        }
    }

    // func. for does key exist
    bool exist(string key){
        int idx = hashFunction(key);

        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key){ // found
                return true;
            }
            temp = temp->next;
        }

        return false;
    }

    int search(string key){
        int idx = hashFunction(key);

         Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key){ // found
                return temp->val;
            }
            temp = temp->next;
        }

        return -1;
    }

    // remove operation
    void remove(string key){
        //step 1: find idx
        int idx = hashFunction(key);

        Node* temp = table[i];
        Node* prev = temp;
        while(temp != NULL){
            if(temp->key == key){ //erase
                if(prev == temp) //head
                table[idx] = temp->next;
            } else {
                prev->next = temp->next;
            }
            break;
        }

        prev = temp;
        temp = temp->next;

    }

    // we can print the hashTable
    void print(){
        for(int i=0; i<totSize; i++){
            cout << "idx" << i << "->";
            Node* temp = table[i];
            while(temp != NULL){
                cout << "(" << temp->key << "," << temp->val << ") ->";
                temp = temp->next;
            }
            cout << endl;
        }
    }

}

int main(){
    HashTable ht;

    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("US", 50);
    ht.insert("Nepal", 10);
    ht.insert("UK", 20);

    // if(ht.exist("India")){
    //     cout << "India population : " << ht.search("India")<< endl;
    // }

    // cout << ht.print();

    // ht.remove("China");
    // ht.print();
    
    return 0;
}