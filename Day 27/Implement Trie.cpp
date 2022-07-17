class TrieNode{
    public:
    TrieNode* children[26];
    char data;
    bool isTerminal;
    
    TrieNode(char ch) {
        data = ch;
        
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }     
        isTerminal = false;
    }  
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertWord(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        
        int index = word[0] - 'a';
        TrieNode* child;
        
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        
        insertWord(child, word.substr(1));
    }
    
    void insert(string word) {
         insertWord(root, word);
    }
    
    bool searchWord(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
            return root->isTerminal;
        }
        
        int index = word[0] - 'a';
        TrieNode* child;
        
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else{
            return false;
        }
        
        return searchWord(child, word.substr(1));
    }
    
    bool search(string word) {
         return searchWord(root, word);
    }

    bool searchPrefix(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
            return true;
        }
        
        int index = word[0] - 'a';
        TrieNode* child;
        
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else{
            return false;
        }
        
        return searchPrefix(child, word.substr(1));
    }
    
    bool startsWith(string prefix) {
         return searchPrefix(root, prefix);
    }
};
