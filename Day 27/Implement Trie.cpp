class TrieNode {
 public:
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = 0;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insertWord(int i, string word, TrieNode* root) {
        
        if(i == word.size()) {
            root -> isTerminal = 1;
            return;
        }
        
        int ind = word[i] - 'a';
        TrieNode* child;
        
        if(root -> children[ind] == NULL) {
            child = new TrieNode();
            root -> children[ind] = child;
        }
        else {
            child = root -> children[ind];
        }
        
        insertWord(i+1, word, child);
    }
    
    void insert(string word) {
        insertWord(0, word, root);
    }
    
    bool search(string word) {
        
        TrieNode* curr = root;
        
        for(int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            if(curr -> children[ind]) {
                curr = curr -> children[ind];
            }
            else {
                return false;
            }
        }
        return curr -> isTerminal;
    }
    
    bool startsWith(string prefix) {
        
        TrieNode* curr = root;
        
        for(int i = 0; i < prefix.size(); i++) {
            int ind = prefix[i] - 'a';
            if(curr -> children[ind]) {
                curr = curr -> children[ind];
            }            
            else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
