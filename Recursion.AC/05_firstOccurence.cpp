#include<iostream>
#include<vector>
using namespace std;

int FirstOccurence(vector<int> arr, int i, int target){
// when vector arr, then no need to of n or size
    int n=arr.size();
    if(i == n){
        return -1;
    }

    if(arr[i] == target){
        return i;
    }

    return FirstOccurence(arr, i+1, target);

}

int main(){
    vector<int> arr = {1,2,3,3,3,4};
    cout << FirstOccurence(arr, 0, 49);
    return 0;
}