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
            
            if(curr && curr -> children[1-bit]) {
                maxi = maxi | (1 << i);
                curr = curr -> children[1-bit];
            }
            else if(curr && curr -> children[bit]){
                curr = curr -> children[bit];
            }
        }
        return maxi;
    }
    
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = queries.size();
        vector<vector<int>> q(n);
        
        for(int i = 0; i < n; i++) {
            q[i] = {queries[i][1], queries[i][0], i};
        }
        
        sort(q.begin(), q.end()); 
        sort(nums.begin(), nums.end());
        
        TrieNode* root = new TrieNode();
        vector<int> ans(n);
        int j = 0;
        
        for(int i = 0; i < n; i++) {
            int m = q[i][0], x = q[i][1], ind = q[i][2];
            
            while(j < nums.size() && nums[j] <= m) {
                insert(nums[j], root);
                j++;
            }
            
            ans[ind] = j == 0 ? -1 : getMax(x, root);
        }
        return ans;
    }
};
