#include<algorithm>
double median(vector<int> a, vector<int> b)
{
vector<double> c;

    for(int i = 0; i < a.size(); i++) {
        c.push_back(a[i]);
    }
    for(int j = 0; j < b.size(); j++) {
        c.push_back(b[j]);
    }
    sort(c.begin(), c.end());

    int s = 0;
    int e = c.size()-1;
    int mid = s + (e-s)/2;
    double median = -1;

    if(c.size()%2 == 0) {
       median = (c[mid] + c[mid+1])/2;
    }
    else{
        median = c[mid];
    }
    return median;
}
