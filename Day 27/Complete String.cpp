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

class Solution {
private:
    void insert(string &word, TrieNode* root) {
        
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
    
public:
    string completeString(int n, vector<string> &a){

        TrieNode* root = new TrieNode();

        for(auto word: a) {
            insert(word, root);
        }

        string ans = "";
        
        for(auto word: a) {
            if(isPresent(word)) {
                if(word.size() > ans.size()) {
                    ans = word;
                }
                else if(word.size() == ans.size()) {
                    ans = min(ans, word);
                }
            }
        }
        return ans;
    }
};
