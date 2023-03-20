class Solution {
public:
	void shortest_distance(vector<vector<int>>&matrix){

	    int n = matrix.size();

	    for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
		    for(int j = 0; j < n; j++) {
			if(matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX) {
			    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		    }
		}
	    }
	}
};
