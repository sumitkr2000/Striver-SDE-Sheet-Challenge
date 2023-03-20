class Solution {
public:
	vector<int> Solution::repeatedNumber(const vector<int> &A) {

	    int n = A.size();
	    int xor1 = A[0];

	    for (int i = 1; i < n; i++) {
		xor1 = xor1^A[i];

	    }
	    for (int i = 1; i <= n; i++) {
		xor1 = xor1^i;
	    }

	    int set_bit_no = xor1 & ~(xor1-1);
	    int x = 0, y = 0;

	    for (int i = 0; i < n; i++) {
		if(A[i] & set_bit_no) {
		    x = x^A[i];
		}
		else {
		    y = y^A[i];
		}
	    }

	    for(int i = 1; i <= n; i++) {
		if(i & set_bit_no) {
		    x = x^i;
		}
		else {
		    y = y^i;
		}
	    }

	    int x_count = 0;
	    for(int i = 0; i < n1; i++) {
		if(A[i] == x) {
		    x_count++;
		}
	    }

	    if(x_count == 0) {
		return {y, x};
	    }

	    return {x, y};
	}
}:
