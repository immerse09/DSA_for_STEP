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


class Info{
    public:
    bool isBST;
    int min;
    int max;
    int sz;

    Info(bool isBST, int min, int max, int sz){
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->sz = sz;
    }
};

// we'll return ptr of this class object in our function

static int maxSize;
// if it ask to return root of largest 
// static Node* largestRoot;

Info* largestBST(Node* root){
    // base case
    // if(root == NULL){
    //     new Info(true, INT_MAX, INT_MIN, 0);
    // }

    // or
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right){
        return new Info(true, root->data, root->data, 1);
    }

    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = lergestBST(root->right);

    int currMin = min(root->data, min(leftInfo->min, rightInfo->min));
    int currMax = max(root->data, min(leftInfo->max, rightInfo->max));
    int currSz = leftInfo->sz + rightInfo->sz + 1;

    // checking 4th i.e 1st that isBST valid or not
    // valid condition
    if(leftInfo->isBST && rightInfo->isBST
    && root->data > leftInfo->max
    && root->data < rightInfo->min){
        maxSize = max(maxSize, currSz);
        return new Info(true, currMin, currMax, currSz);
    }
    // invalid condition
    return new Info(false , currMin, currMax, currSz);

}

int main(){
    Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

    largestBST(root);
    cout << "max size : " << maxSize << endl;

    return 0;

}