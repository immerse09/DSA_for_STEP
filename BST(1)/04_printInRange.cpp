void printInRange(Node* root, int start, int end){
    if(root == NULL){
        return;
    }

    if(start <= root->data && root->data <= end){ //case1
        printInRange(root->left, start, end);
        cout << root->data << " ";
        printInRange(root->right, start, end);
    } else if(root->data <start){ //case2
        printInRange(root->right, start, end);
    } else {// case3
        printInRange(root->left, start, end);
    }
}

