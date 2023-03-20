class TrieNode {
public:
    TrieNode* children[2]; 
};

class Solution {
private:
    void insert(int num, TrieNode* root) {
        
        TrieNode* curr = root;
        
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            
            if(!curr -> children[bit]) {
                curr -> children[bit] = new TrieNode();
            }
            curr = curr -> children[bit];
        }
    }
    
    int getMax(int num, TrieNode* root) {
        
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
    
public:
    int findMaximumXOR(vector<int>& nums) {
        
        int n = nums.size();
        TrieNode* root = new TrieNode();
        int ans = INT_MIN;
        
        for(int i = n-1; i >= 0; i--) {
            insert(nums[i], root);
            ans = max(ans, getMax(nums[i], root));
        }
        return ans;
    }
};
