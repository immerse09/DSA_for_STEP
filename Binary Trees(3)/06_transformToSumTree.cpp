#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Node{
    int data;
    Node* left;
    Node* right;

    public:
    Node(int data){
        this->data = data;
        left= right= NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> nodes){
    idx++;

    if(nodes[idx] == -1){
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right= buildTree(nodes);

    return currNode;
}

// in rec. we need 3 parameter 
// this func. will be recursive
void kthHelper(Node* root, int k, int currLevel){
    if(root == NULL){
        return;
    }

    if(currLevel == k){
        cout << root->data << " ";
        return;
    }

    kthHelper(root->left, k, currLevel+1); //left
    kthHelper(root->right, k, currLevel+1); //right

}

// code for transform to sum tree
int transform(Node* root){ //O(n)
    if(root == NULL){
        return 0;
    }

    int leftOdld = transform(root->left);
    int rightOld = transform(root->right);
    int currOld = root->data;

    root->data = leftOld + rightOld; 

    if(root->left != NULL)
        root->data += root->left->data;

    if(root->right != NULL)
        root->data += root->right->data;

    
    return currOld;
}


void kthLevel(Node* root, int k){ //O(n)
    kthHelper(root, k, 1);
    cout << endl;
}




int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

transform(root);
levelOrder(root);

    return 0;
}