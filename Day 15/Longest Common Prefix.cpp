class TrieNode {
public:
    int childCnt;
    bool isTerminal;
    TrieNode* children[26];
    
    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCnt = 0;
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
                curr -> childCnt++;
            }
            curr = curr -> children[ind];
        }
        curr -> isTerminal = true;
    }
    
    string getPrefix(string &word, TrieNode* root) {
        
        TrieNode* curr = root;
        string ans = "";
        
        for(auto &it: word) {
            if(curr -> childCnt != 1 || curr -> isTerminal) {
                return ans;
            }
            
            ans += it;
            curr = curr -> children[it - 'a'];
        }
        return ans;
    }
    
public:
    string longestCommonPrefix(vector<string>& strs) {
             
        //Approach 1: By sorting
        int n = strs.size();
        sort(strs.begin(), strs.end());
        
        string first = strs[0], last = strs[n-1];
        string ans = "";
        
        for(int i = 0; i < first.size(); i++) {
            if(first[i] != last[i]) {
                return ans;
            }
            ans += first[i];
        }
        
        return ans;
        
        /*//Approach 2: Using Trie
        TrieNode* root = new TrieNode();
        
        for(int i = 0; i < strs.size(); i++) {
            if(strs[i].size() == 0) {
                return "";
            }
            insert(strs[i], root);
        }
        
        return getPrefix(strs[0], root);
        */
    }
};
