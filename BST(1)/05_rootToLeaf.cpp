void printPath(vector<int> path){
    cout << "path : ";
    for(int i=0; i<path.size(); i++){
        cout << path[i] <<< " ";
    }
    cout << endl;
}

void pathHelper(Node* root, vector<int> &path){
    if(root == NULL){
        return;
    }
    path.push_back(root->data);

    if(root->left == NULL && root->right == NULL){ // leaf
        printPath(path);
        path.pop_back();
        return;
    }

    pathHelper(root->left, path);
    pathHelper(root->right, path);

    path.pop_back();
}

void rootToLeafPath(Node* root){
    vector<int> path;
    pathHelper(root, path);
}