#include<map>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL) {
        return ans;
    }

    map<int, map<int, vector<int> > > mp;
    queue<pair< TreeNode<int>*, pair<int, int> > > q;

    q.push(make_pair(root, make_pair(0, 0)));

    while(!q.empty()) {

        pair< TreeNode<int>*, pair<int, int> > temp = q.front();
        q.pop();

        TreeNode<int>* frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        mp[hd][level].push_back(frontNode -> data);

        if(frontNode -> left) {
            q.push(make_pair(frontNode -> left, make_pair(hd-1, level+1)));
        }
        if(frontNode -> right) {
            q.push(make_pair(frontNode -> right, make_pair(hd+1, level+1)));
        }
    }

    for(auto i: mp) {
        for(auto j: i.second) {
            for(auto k: j.second) {
                ans.push_back(k);
            }
        }
    }
    return ans;
}
