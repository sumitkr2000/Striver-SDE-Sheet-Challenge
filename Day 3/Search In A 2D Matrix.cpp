#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    int s = 0;
    int e = m * n - 1;
    int mid = s + (e-s)/2;

    while(s <= e) {

        int element = mat[mid/n][mid%n];

        if(element == target) {
            return 1;
        }
        else if(element < target) {
            s = mid + 1;
        }
        else{
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return 0;
}
