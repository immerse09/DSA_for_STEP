
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

class Node {
    public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    int freq;

    Node(){
        endOfWord = false;
    }
};

class Trie {
    Node* root;
    public:
    Trie(){
        root = new Node();
        root->freq = -1;
    }

    // ---- Inserting key in Trie-----(insertion)
    void insert(string key){ //O(L)
        Node* temp = root;

        for(int i=0; i<key.size(); i++){
            //every time search key[i] in root's children
            if(temp->children.count(key[i]) == 0){ // doesn't exist
                temp->children[key[i]] = new Node(); // insert
                temp->children[key[i]]->freq = 1;
            } else {
                temp->children[key[i]]->freq++;
            }
            // update temp
            temp = temp->children[key[i]];
        }

        temp->endOfWord = true;
    }


    string getPrefix(string key){
        Node* temp = root;
        string prefix = "";

        for(int i=0; i<key.size(); i++){
            prefix += key[i];
            if(temp->children[key[i]]->freq == 1){
                break;
            }
            temp = temp->children[key[i]];
        }
        return prefix;
        
    }

};

void prefixProblem(vector<string> dict){ //O(n*L)
    Trie trie;
    for(int i=0; i<dict.size(); i++){
        trie.insert(dict[i]);
    }

    for(int i=0; i<dict.size(); i++){
        cout << trie.getPrefix(dict[i]) << endl;
    }
}

int main(){
    vector<string> dict = {"zebra", "dog", "duck", "dove"};


    prefixProblem(dict);

    return 0;
}
