class Solution {
private:
	double multiply(double m, int n) {

	    double prod = 1.0;
	    for(int i = 1; i <= n; i++) {
		prod *= m;
	    }
	    return prod;
	}

public:
	double findNthRootOfM(int n, int m) {

	    double s = 1, e = m, eps = 1e-9;

	    while(e - s > eps) {
		double mid = s + (e - s)/2.0;

		if(multiply(mid, n) < m) {
		    s = mid;
		}
		else {
		    e = mid;
		}
	    }
	    return s;
	}
};
