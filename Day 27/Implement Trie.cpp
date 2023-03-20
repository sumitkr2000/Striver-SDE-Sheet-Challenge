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
    
    void insert(string word) {
        
        TrieNode* curr = root;
        
        for(auto &it: word) {
            int ind = it - 'a';
            
            if(!curr -> children[ind]) {
                curr -> children[ind] = new TrieNode();
            }
            curr = curr -> children[ind];
        }
        curr -> isTerminal = true;
    }
    
    bool search(string word) {
        
        TrieNode* curr = root;
        
        for(auto &it: word) {
            int ind = it - 'a';
            
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
        
        for(auto &it: prefix) {
            int ind = it - 'a';
            
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
