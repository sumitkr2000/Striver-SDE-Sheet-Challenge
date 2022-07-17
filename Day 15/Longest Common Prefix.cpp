string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans ="";
    
    for(int i = 0; i < arr[0].size(); i++) {
        string first = arr[0];
        bool flag = true;
        for(int j = 1; j < n; j++) {
            string temp = arr[j];
            if(first[i] != temp[i]) {
                flag = false;
                break;
            }
        }
        if(flag == false) {
            break;
        }
        else{
            ans.push_back(first[i]);
        }
    }
    return ans;
}
