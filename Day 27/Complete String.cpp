#include <bits/stdc++.h> 
class TrieNode {
public:
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode() {
        for(int i = 0; i < 25; i++) {
            children[i] = NULL;
        }
        isTerminal = 0;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insertWord(int i, string &word, TrieNode* root) {
        
        if(i == word.size()) {
            root -> isTerminal = 1;
            return;
        }
        
        int ind = word[i] - 'a';
        TrieNode* child;
        
        if(root -> children[ind]) {
            child = root -> children[ind];
        }
        else {
            child = new TrieNode();
            root -> children[ind] = child;
        }
        
        insertWord(i+1, word, child);
    }
    
    void insert(string &word) {
        insertWord(0, word, root);
    }
    
    bool isPresent(string &word) {
        
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            curr = curr -> children[ind];
            if(!curr -> isTerminal) {
                return false;
            }
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    
    Trie* t = new Trie();
    
    for(auto word: a) {
        t -> insert(word);
    }
    
    string ans = "";    
    for(auto word: a) {
        if(t -> isPresent(word)) {
            if(word.size() > ans.size()) {
                ans = word;
            }
            else if(word.size() == ans.size()) {
                ans = min(ans, word);
            }
        }
    }
    return ans == "" ? "None" : ans;
}
