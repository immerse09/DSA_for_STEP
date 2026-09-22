int count(Node* root){
    if(root == NULL){
        return 0;
    }
    
    int leftCount = count(root->left);
    int rightCount = count(root->right);

    return leftCount + rightCount + 1;
}

// we can make another tree and find count
Node* root2 = new Node(5);
root2->left = new Node(3);
root2->right = new Node(4);

cout << count(root2) << endl;