#include<vector>
string reverseString(string str)
{
    vector<string> container;
    string temp = "";
    for(int i = 0; i < str.length(); i++) {

        if(temp.empty() && str[i] == ' ') {
            continue;
        }

        if(i == str.length()-1 && str[i] != ' ') {
            temp.push_back(str[str.length()-1]);
            container.push_back(temp);
        }

        if(!temp.empty() && str[i] == ' ') {
            container.push_back(temp);
            temp.clear();
        }

        if(str[i] != ' ') {
            temp.push_back(str[i]);
        }
    }


    string ans = "";  

    for(int i = container.size()-1; i >= 0; i--) {
        ans += container[i];
        if(i != 0) {
            ans.push_back(' ');
        }

    }        
    return ans;
}
