class TrieNode {
public:
    TrieNode* children[26];
    
    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Solution {
private:
    void insert(int i, string &word, TrieNode* root, int &cnt) {
        
        TrieNode* curr = root;
        
        for(auto &it: word) {
            int ind = it - 'a';
            
            if(!curr -> children[ind]) {
                curr -> children[ind] = new TrieNode();
                cnt++;
            }
            curr = curr -> children[ind];
        }
    }
    
public:
    int countDistinctSubstrings(string &s) {
        
        int n = s.size();
        TrieNode* root = new TrieNode();
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            string temp = "";
            for(int j = i; j < n; j++) {
                temp += s[j];
                insert(0, temp, root, cnt);
            }
        }
        return cnt + 1;
    }
};
