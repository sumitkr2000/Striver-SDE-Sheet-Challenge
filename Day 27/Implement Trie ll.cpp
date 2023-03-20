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
    
    void insert(string &word){
        
        TrieNode* curr = root;
        
        for(auto &it: word) {
            int ind = it - 'a';
            
            if(!curr -> children[ind]) {
                curr -> children[ind] = new TrieNode();
            }
            curr = curr -> children[ind];
            curr -> prefixCnt++;
        }
        curr -> wordCnt++;
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
