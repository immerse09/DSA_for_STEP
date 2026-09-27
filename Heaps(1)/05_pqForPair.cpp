#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Heap {
     vector<int> vec; //CBT, max Heap
     public:

     void push(int val){
        // step 1
        vec.push_back(val); // child

        // fix heap
        int x = vec.size()-1; //childI
        int parI = (x-1)/2;

        while(parI >= 0 && vec[x] > vec[parI]){
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x-1)/2;
        }
     }

     void pop(){

     }

     int top(){ //O(1)
        return vec[0]; //heighest priority element
     }

     bool empty(){
        return vec.size() == 0;
     }
    
};

// class Student { // "<" overload
//     public:
//     string name;
//     int marks;

//     Student(string name, int marks){
//         this->name = name;
//         this->marks = marks;
//     }
// // logic to defined on which basis we want priority
// // operator overloading

// // on the basis of marks and max Heap | < i.e default maxm
// bool operator < (const Student &obj) const {
//     return this->marks > obj.marks;
// }
// // on the basis of name
// // bool operator < (const Student &obj) const {
// //     return this->name < obj.marks;

// };


// to store , we'll make struct
// want outpur on basis of second value of pair
struct ComparePair {
    bool operator () (pair<string, int> &p1, pair<string, int> &p2){
        return p1.second < p2.second; // '<' maxHeap, for minHeap '>'
    }
};


int main(){
   //priority_queue<pair<string, int>> pq; //default - maxHeap; "first"

    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq;
    // on basis of second value of pair

   pq.push(make_pair("aman", 85));
   pq.push(make_pair("suman", 98));
   pq.push(make_pair("chetan", 115));

   while(!pq.empty()){
    cout << "top = " << pq.top().first << "," << pq.top().second << endl;
    pq.pop();
   }
    return 0;
}