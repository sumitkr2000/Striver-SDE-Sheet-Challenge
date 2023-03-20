class Solution {
private:
    static bool comp(Item a, Item b) {
        
        double vpw1 = double(a.value)/double(a.weight);
        double vpw2 = double(b.value)/double(b.weight);
        
        return vpw1 > vpw2;
    }
    
public:
    double fractionalKnapsack(int W, Item arr[], int n) {
        
        sort(arr, arr+n, comp);
        double ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(W >= arr[i].weight) {
                ans += double(arr[i].value);
                W -= arr[i].weight;
            }
            else {
                ans += (double(arr[i].value)/double(arr[i].weight) * (double)W);
                break;
            }
        }
        return ans;
    }
        
};
