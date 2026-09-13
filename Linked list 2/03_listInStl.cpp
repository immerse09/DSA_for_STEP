#include<iostream>
#include<list>
#include<iterator>
using namespace std;

// to print the value of list
void printList(list<int> ll){
    list<int>::iterator itr;
    for(itr = ll.begin(); itr != ll.end(); itr++){
        cout << (*itr) << " -> "; // it give data of node
    }
    cout << "NULL" << endl;
}

int main(){
    list<int> ll;

    ll.push_front(2);
    ll.push_front(1);

    ll.push_back(3);
    ll.push_back(4);

    printList(ll);
    cout << ll.size() << endl;

    cout << "head = " << ll.front() << endl;
    cout << "tail = " << ll.back() << endl;

    ll.pop_back();
    printList(ll);
    return 0;
}
