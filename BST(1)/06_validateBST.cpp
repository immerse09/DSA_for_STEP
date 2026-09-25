bool validateHelper(Node* root, Node* min, Node* max){
    if(root == NULL){
        return true;
    }

    if(min != NULL && root->data < min->data){
        return false;
    }

    if(max != NULL && root->data > max->data){
        return false;
    }

    return validateHelper(root->left, min, root->data) 
        && validateHelper(root->right, root->data, max)
}

bool validateBST(Node* root){
    return validateHelper(root, NULL, NULL);
}