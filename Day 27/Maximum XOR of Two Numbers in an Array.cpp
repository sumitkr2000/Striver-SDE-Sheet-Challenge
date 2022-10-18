class TrieNode {
public:
    TrieNode* children[2]; 
};

class Trie {
private:
    TrieNode* root;    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int num) {
        
        TrieNode* curr = root;
        
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!curr -> children[bit]) {
                curr -> children[bit] = new TrieNode();
            }
            curr = curr -> children[bit];
        }
    }
    
    int getMax(int num) {
        
        TrieNode* curr = root;
        int maxi = 0;
        
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            
            if(curr -> children[1-bit]) {
                maxi = maxi | (1 << i);
                curr = curr -> children[1-bit];
            }
            else {
                curr = curr -> children[bit];
            }
        }
        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        int n = nums.size();
        Trie* t = new Trie();
        int ans = INT_MIN;
        
        for(int i = n-1; i >= 0; i--) {
            t -> insert(nums[i]);
            ans = max(ans, t -> getMax(nums[i]));
        }
        return ans;
    }
};
