#include<iostream>
using namespace std;

void stockSpanProblem(vector<int> stock, vector<int> span){
    stack<int> s;
    span[0] = 1;
    s.push(0);

    for(int i=0; i<stock.size(); i++){
        int currPrice = stock[i];
        while(!s.empty() && currPrice >=s.top()){
            s.pop();
        }
            if(s.empty()){
            span[i] = i+1;
            } else {
                int prevHigh = s.top();
                span[i] = i-prevHigh;
            }
        
    }

    for(int i=0; i<span.size(); i++){
        cout << span[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span = {0, 0, 0, 0, 0, 0, 0};

    stockSpanProblem(stock, span);
    return 0;
}
