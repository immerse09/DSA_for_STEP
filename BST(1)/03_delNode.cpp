Node* getInorderSuccessor(Node* root){
    while(root->left != NULL){
        root = root->left;
    }

    return root; //IS
}

Node* delNode(Node* root, int val){
    if(root == NULL){
        return NULL;
    }

    if(val < root->data){ //left subtree
        root->left = delNode(root->left, val);
    } else if(val > root->data){ //right subtree
        root->right = delNode(root->right, val);
    } else {
        // root == val
        // case1 : 0 children
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // case2 : 1 child
        if(root->left == NULL && root->right == NULL){
            return root->left == NULL ? root->right : root->left;

        }

        // case3 : 2 children
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = delNode(root->right, IS->data); //case1, case2
        return root;
    }
    return root;
}

