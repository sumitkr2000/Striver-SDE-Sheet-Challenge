#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	
    vector<int> v;
        
    int i = 0;
    int j = 0;

    while(i < m && j < n) {
        if(arr1[i] < arr2[j]) {
            v.push_back(arr1[i]);
            i++;
        }
        else {
            v.push_back(arr2[j]);
            j++;
        }
    }
    while(i < m) {
        v.push_back(arr1[i]);
        i++;
    }
    while(j < n) {
        v.push_back(arr2[j]);
        j++;
    }
    return v;
}
