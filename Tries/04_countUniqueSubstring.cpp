#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

class Node {
    public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node(){
        endOfWord = false;
    }
};

class Trie {
    Node* root;
    public:
    Trie(){
        root = new Node();
    }

    // ---- Inserting key in Trie-----(insertion)
    void insert(string key){ //O(L)
        Node* temp = root;

        for(int i=0; i<key.size(); i++){
            //every time search key[i] in root's children
            if(temp->children.count(key[i]) == 0){ // doesn't exist
                temp->children[key[i]] = new Node();
            }
            // update temp
            temp = temp->children[key[i]];
        }

        temp->endOfWord = true;
    }


    // ----- Searching key in Trie----(searching)
    bool search(string key){ //O(L)
        Node* temp = root;
        
        for(int i=0; i<key.size(); i++){
            if(temp->children.count(key[i])){
                temp = temp->children[key[i]];
            } else {
                return false;
            }
        }

        return temp->endOfWord;
    }


    int countHelper(Node* root){
        int ans = 0;

        for(pair<char, Node*> child : root->children){
            ans += countHelper(child.second);
        }
        return ans + 1;
    }

    int countNodes(){
        return countHelper(root);
    }

};

int countUniqueSubstr(string str){
        Trie trie;
        // find suffix
        for(int i=0; i<str.size(); i++){
            string suffix = str.substr(i);
            trie.insert(suffix);
        }
        return trie.countNodes();
    }

    int main(){
        string str = "ababa";

        cout << countUniqueSubstr(str) <<endl;
        return 0;
    }