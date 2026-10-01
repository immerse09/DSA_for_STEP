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

    bool startsWith(string prefix){ //O(L)
        Node* temp = root;

        for(int i=0; i<prefix.size(); i++){
            if(temp->children[prefix[i]]){
                temp = temp->children[prefix[i]];
            } else {
                return false;
            }
        }
        return true;
    }


};

int main(){
    vector<string> words = {"apple", "app", "mango", "man", "women"};

    Trie trie;
    for(int i=0; i<words.size(); i++){
        trie.insert(words[i]);
    }

    cout << trie.startsWith("wem") << endl;
    return 0;
}