#include<iostream>
#include<vector>
using namespace std;

class Queue {
    // declaring some pointer

    // ptr for dynamic array
    int* arr;

    int capacity;
    int currSize;

    int f, r;
public:
    Queue(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;
        f= 0;
        r=-1;
        
    }


    void push(int data){ // O(1)
        if(currSize == capacity){
            cout << "Queue is full\n";
            return;
        }

        r = (r + 1) % capacity;
        arr[r] = data;
        currSize++;
    }
    void pop(){ // O(1)
        if(empty()){
            cout << "Queue is empty\n";
            return;
        }

        f = (f + 1) % capacity;
        currSize--;
    }
    void front(){ // O(1)
        if(empty()){
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[f];
    }

    bool empty(){ // O(n)
        return currSize ==0;
    }


};

int main(){
    // here, we'll pass fixed size of array 
    Queue q(4);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.push(5);
    cout << q.front() << endl;
    return 0;
    
}