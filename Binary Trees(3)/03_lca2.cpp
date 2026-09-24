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


void kthLevel(Node* root, int k){ //O(n)
    kthHelper(root, k, 1);
    cout << endl;
}


// code for lca
bool rootToNodePath(Node* root, int n, vector<int> &path){ // O(n)
    if(root == NULL){
        return false;
    }

    path.push_back(root->data);
    if(root->data == n){
        return true;
    }

    int isLeft = rootToNodePath(root->left, n, path);
    int isRight = rootToNodePath(root->right, n, path);

    if(isLeft || isRight){ // either true
        return true;
    }

    path.pop_back();
    return false;
}


int LCA(Node* root,int n1,int n2){ //O(n), O(n)
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);

    int lca = -1;
    for(int i=0, j=0 i<path1.size() && j<path2.size(); i++, j++){
        if(path[i] != path[j]){
            return lca;
        }
        lca = path1[i];
    }
    return lca;
}

// approach 2 for lca
Node* LCA2(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    if(leftLCA != NULL && rightLCA != NULL){
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA;


}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    // kthLevel(root, 2);
    int n1 = 4, n2 = 5; // lca = 2
    // cout << "lcs = " << LCA(root, n1, n2) << endl;
    cout << "lca2 = " << LCA2(root, n1, n1)->data << endl;


    return 0;
}