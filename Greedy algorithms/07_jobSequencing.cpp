#include<iostream>
#include<vector>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    // sort on the basis of profit i.e on second value
    return p1.second > p2.second; 
}

int maxProfit(vector<pair<int, int>> job){
    sort(job.begin(), job.end(), compare);
    // first-> deadline; second -> profit

    int profit = job[0].second;
    int safeDeadline = 2;

    for(int i=1; i<job.size(); i++){
        if(job[i].first >= safeDeadline){
            profit += job[i].second;
            safeDeadline++;
        }
    }

    cout << "max profit from jobs : " << profit << endl;
    return profit;

}

int main(){
    int n=4;
    vector<pair<int, int>> job(n, make_pair(0, 0));
    job[0] = make_pair(4, 20);
    job[1] = make_pair(1, 10);
    job[2] = make_pair(1, 40);
    job[3] = make_pair(1, 30);

    maxProfit(job);
}
   
