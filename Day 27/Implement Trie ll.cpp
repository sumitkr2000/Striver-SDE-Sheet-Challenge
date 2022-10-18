#include <bits/stdc++.h> 
class TrieNode {
public:
    TrieNode* children[26];
    int wordCnt;
    int prefixCnt;
    
    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        wordCnt = 0;
        prefixCnt = 0;
    }
};

class Trie{
private:
    TrieNode* root;   
public:
    Trie(){
        root = new TrieNode();
    }

    void insertWord(int i, string word, TrieNode* root) {
        
        if(i == word.size()) {
            root -> wordCnt++;
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
       
        child -> prefixCnt++;
        
        insertWord(i+1, word, child);
    }
    
    void insert(string &word){
        insertWord(0, word, root);
    }

    int countWordsEqualTo(string &word){
        
        TrieNode* curr = root;        
        for(int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            if(curr -> children[ind]) {
                curr = curr -> children[ind];
            }
            else {
                return 0;
            }
        }       
        return curr -> wordCnt;
    }

    int countWordsStartingWith(string &word){
        
        TrieNode* curr = root;        
        for(int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            if(curr -> children[ind]) {
                curr = curr -> children[ind];
            }
            else {
                return 0;
            }
        }
        
        return curr -> prefixCnt; 
    }

    void erase(string &word){
        
        TrieNode* curr = root;       
        for(int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            curr = curr -> children[ind];
            curr -> prefixCnt--;
        }
        curr -> wordCnt--;
    }
};
