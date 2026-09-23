
bool isIdentical(Node* root1, Node* root2){
    if(root1->data == root2->data == NULL){
        return true;
    }

    if(root1->data == NULL || root2->data == NULL){
        return false;
    }

    if(root1->data != root2->data){
        return false;
    } 
        return isIdentical(root1->left, root2->left) 
            && isIdentical(root1->right, root2->right);
            return true;
        
    }


// func. for checking subtree or not
bool isSubtree(Node* root, Node* subRoot){
    // base case
    if(root == NULL && subRoot == NULL){
        return true;
    }else if(root == NULL || subRoot == NULL){
        return false;
    }
    if(root->data == isSubRoot->data){
        // check poora loop i.e identical (structure and nodes values)
        // it is also important though
        isIdentical(root, subRoot){
            return true
        }

// false
    } // else

    int isLeftSubtree = isSubtree(root->left, subRoot);

    if(!isLeftSubtree){
        return isSubtree(root->right, subRoot);
    }
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6,  -1, -1};
    Node* root = buildTree(nodes);

    // subtree
    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);

    cout << isSubtree(root, subRoot) << endl; //1
    return 0;
}