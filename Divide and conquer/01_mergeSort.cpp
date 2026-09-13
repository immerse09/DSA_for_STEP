#include<iostream>
#include<vector>
using namespace std;

// merger func.
// this step or func. is for only combining step
void merge(int arr[], int si, int mid, int ei){ // O(n)
    vector<int> temp;
    int i=si;
    int j=mid+1;

    while(i <= mid && j <= ei){
        if(arr[i] <= arr[j]){
        temp.push_back(arr[i++]);
    } else {
        temp.push_back(arr[j++]);
    }
    }

    while(i <= mid){
        temp.push_back(arr[i++]);
    }

    while(j <= ei){
        temp.push_back(arr[j++]);
    }

    // vector -> org. arr or copying
    for(int idx=si, x=0; idx<=ei; idx++){ // org. arr
        arr[idx] = temp[x++];
    }
}

 // recurrence func. or code
void mergeSort(int arr[], int si, int ei){ // O(nlogn)

    int mid = (si + ei) / 2; // si + (ei - si)/2

    mergeSort(arr, si, mid); // left half
    mergeSort(arr, mid+1, ei); // right half
    
    merge(arr, si, mid, ei); // conquer
}

// func. to print arr
void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
        cout << endl;
}

int main(){
    int arr[6] = {6, 3, 7, 5, 2, 4};
    int n = 6;

    mergeSort(arr, 0, n-1);
    printArr(arr, n);
    return 0;
}