#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size();
    int m = matrix[0].size();        
    vector<pair<int,int> > v;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                v.push_back({i,j});
            }
        }
    }

    for(int i = 0; i < v.size(); i++) {
        int row = v[i].first;
        int col = v[i].second;

        for(int j = 0; j < n; j++) {
            matrix[j][col] = 0;
        }

        for(int k = 0; k < m; k++) {
            matrix[row][k] = 0;
        }
    }
}
