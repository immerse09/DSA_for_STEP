#include<iostream>
#include<unordered_map>
using namespace std;

void majorityElement(vector<int> nums){
    int n=nums.size();

    unordered_map<int, int> m; // element, freq

    for(int i=0; i<n; i++){ //O(n)
        if(m.count(nums[i])){ //O(1)
            m[nums[i]]++;
        } else {
            m[nums[i]] = 1;
        }
    }

        for(pair<int, int> p : m){
            if(p.second > n/3){
            cout << p.first;
            }
        }

        cout << endl;
    
}

int main(){
    vector<int> nums = {1, 3, 2, 5, 1, 3, 1, 5, 1};
    vector<int> nums2 = {1, 2};

    // majorityElement(nums2);//21
    majorityElement(nums);
    return 0;
}