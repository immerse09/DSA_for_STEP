// void postorder(Node* root){
//     if(root == NULL){
//         return;
//     }

//     // left
//     postorder(root->left);
//     // right
//     postorder(root->right);
//     // root
//     cout << root->data << " ";
// }


#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};


static int idx = -1; // update in every call or ++
// due to static idx, value increse in same var 

Node* buildTree(vector<int> nodes){ // it return ptr of root node
    idx++;
    if(nodes[idx] == -1){
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes); // left subtree
    currNode->right = buildTree(nodes); // right subtree

    return currNode;
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }

    // left
    postorder(root->left);
    // right
    postorder(root->right);
    // root
    cout << root->data << " ";
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes); //1
   
    postorder(root);
    cout << endl;
    return 0;
}

