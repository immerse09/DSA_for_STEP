#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;


void topView(Node* root){
    queue<pair<Node*, int>> Q; //(node, HD)
    map<int, int> m; //(HD, node->data)

    Q.push(make_pair(root, 0));
    while(!Q.empty()){
        pair<Node*, int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;
        int currHd = curr.second;

        if(m.count(currHD) == 0){ //HD -> add in map
            m[currHd] = currNode->data;
        }
        // else me bs ignore so dont write

        if(currNode->left != NULL){
            pair<Node*, int> left = make_pair(currNode->left, currHD-1);
            Q.push(left);
        }

        if(currNode->right != NULL){
            pair<Node*, int> right = make_pair(currNode->right, currHd+1);
            Q.push(right);
        }
    }

    for(auto it : m){
        cout << it.second << " ";
    }
    cout << endl;
}



