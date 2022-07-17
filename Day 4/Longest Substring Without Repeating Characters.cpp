#include<unordered_map>
#include<climits>
int uniqueSubstrings(string input)
{
    int n = input.length();
    if(n == 0) {
       return 0;
     }
        
        unordered_map<char,int> mp;
        int i = 0;
        int j = 0;
        int m = INT_MIN;
        
        while(j<n){
            mp[input[j]]++;
            if(mp.size() == (j-i+1)){
                m = max(m,(j-i+1));
                j++;
            }
            else if(mp.size() < (j-i+1)){
                while(mp.size() < (j-i+1)){
                    mp[input[i]]--;
                    if(mp[input[i]] == 0){
                        mp.erase(input[i]);
                    }
                    i++;
                }
                j++;
            }  
        }
        return m;
}
