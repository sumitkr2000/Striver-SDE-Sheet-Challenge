class TrieNode {
public:
    char data;
    int childCnt;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCnt = 0;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie(char ch) {
        root = new TrieNode(ch);
    }
    
    void insertFxn(TrieNode* root, string word) {
        if(word.size() == 0) {
            root -> isTerminal = true;
            return;
        }
        
        int index = word[0]-'a';
        TrieNode* child;
        
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
            root -> childCnt++;
        }
        
        insertFxn(child, word.substr(1));
    }
    
    void insert(string word) {
        insertFxn(root, word);
    }
    
    void solve(string word, string &ans) {
        
        for(int i = 0; i < word.size(); i++) {
            if(root -> childCnt == 1) {
                ans += word[i];
                root = root -> children[word[i]-'a'];
            }
            else {
                break;
            }
            
            if(root -> isTerminal == true) {
                break;
            }
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        //Approach 1: By sorting
        int n = strs.size();
        sort(strs.begin(), strs.end());
        
        string first = strs[0];
        string last = strs[n-1];
        string ans = "";
        
        for(int i = 0; i < first.size(); i++) {
            if(first[i] != last[i]) {
                return ans;
            }
            ans += first[i];
        }
        
        /*//Approach 2: Using Trie
        Trie* t = new Trie('\0');
        
        for(int i = 0; i < strs.size(); i++) {
            if(strs[i].size() == 0) {
                return "";
            }
            t-> insert(strs[i]);
        }
        
        string ans = "";
        t->solve(strs[0], ans);
        */
        
        return ans;
    }
};
