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

class Student { // "<" overload
    public:
    string name;
    int marks;

    Student(string name, int marks){
        this->name = name;
        this->marks = marks;
    }
// logic to defined on which basis we want priority
// operator overloading

// on the basis of marks and max Heap | < i.e default maxm
bool operator < (const Student &obj) const {
    return this->marks > obj.marks;
}
// on the basis of name
// bool operator < (const Student &obj) const {
//     return this->name < obj.marks;

};

int main(){
   priority_queue<Student> pq;

   pq.push(Student("aman", 85));
   pq.push(Student("suman", 98));
   pq.push(Student("chetan", 115));
    return 0;
}