void findPermutationsfun(string &s, int i, vector<string>& ans) {
        
        //base case
        if(i >= s.length()) {
            ans.push_back(s);
            return;
        }
        
        for(int j = i; j<s.length(); j++) {
            swap(s[i], s[j]);
            findPermutationsfun(s, i+1, ans);
            //backtrack
            swap(s[i], s[j]);
        }
    }

vector<string> findPermutations(string &s) {
    
	vector<string> ans;
    int i = 0;
    findPermutationsfun(s, i, ans);
    return ans;
    }
