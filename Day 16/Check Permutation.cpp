bool areAnagram(string &str1, string &str2){
    
        char s1[26] = {0};
        char t1[26] = {0};
        
        for(int i = 0; i < str1.size(); i++) {
            
            int index = str1[i] - 'a';
            s1[index]++; 
        }
        for(int i = 0; i < str2.size(); i++) {
            
            int index = str2[i] - 'a';
            t1[index]++; 
        }
        
        for(int i = 0; i < 26; i++) {
            
            if(s1[i] != t1[i]) {
                return false;
                break;
            }
        }
        return true;
}
