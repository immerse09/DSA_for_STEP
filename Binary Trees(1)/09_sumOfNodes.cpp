int sum(Node* root){
    if(root == NULL){
        return 0;
    }
     leftSum = sum(root->left);
    rightSum = sum(root->right);

    return leftSum+ rightSum + root->data;
}

// we can print as we think about recursion 
// i.e sum of every level
// like that

 leftSum = sum(root->left);
 rightSum = sum(root->right);

 int currSum = leftSum+ rightSum + root->data;
 cout << "sum = " << currSum << endl;
 return currSum;


