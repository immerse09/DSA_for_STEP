// make pair of diameter, height
pair<int, int> diam2(Node* root){ // O(n)
    if(root == NULL){
        return make_pair(0, 0);
    }

    // (diameter, height)
    pair<int, int> leftInfo = diam2(root->left); //(LD, LH)
    pair<int, int> rightInfo = diam2(root->right); //(RD, RH)

    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDiam, finalHt);
}

// cout << "diameter = " << diam2(root).first << endl; //5