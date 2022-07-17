#include<queue>
class node{
  public:
    int data;
    int row;
    int col;
    
    node(int d, int i, int j){
        this -> data = d;
        this -> row = i;
        this -> col = j;
    }
};

class compare{
  public:
    bool operator()(node* a, node* b) {
        return a -> data > b -> data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    
    priority_queue<node*, vector<node*>, compare> conatainer;
    
    for(int i = 0; i < k; i++) {
        node* temp = new node(kArrays[i][0], i, 0);
        conatainer.push(temp);
    }
    
    vector<int> ans;
    
    while(!conatainer.empty()) {
        node* temp = conatainer.top();
        ans.push_back(temp -> data);
        conatainer.pop();
        
        int i = temp -> row;
        int j = temp -> col;
        
        if(j+1 < kArrays[i].size()) {
            node* next = new node(kArrays[i][j+1], i, j+1);
            conatainer.push(next);
        }
    }
    return ans;
}
