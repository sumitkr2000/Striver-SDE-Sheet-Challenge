class TrieNode {
public:
    TrieNode* children[26];
    
    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
    
    void insert(int i, string &word, TrieNode* root, int &cnt) {
        
        if(i == word.size()) {
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
            cnt++;
        }
        
        insert(i+1, word, child, cnt);
    }
};

int countDistinctSubstrings(string &s)
{
    int n = s.size();
    TrieNode* root = new TrieNode();
    int cnt = 0;
    
    for(int i = 0; i < n; i++) {
        string temp = "";
        for(int j = i; j < n; j++) {
            temp += s[j];
            root -> insert(0, temp, root, cnt);
        }
    }
    return cnt + 1;
}
