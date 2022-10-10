class Codec {
public:
    string serialize(TreeNode* root) {
        
        string ans = "";
        
        if(root == NULL) {
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {            
            TreeNode* front = q.front();
            q.pop();
            
            if(front == NULL) {
                ans += "#,";
            }
            else {
                ans += to_string(front -> val) + ',';
            }

            if(front != NULL) {
                q.push(front -> left);
                q.push(front -> right);
            }
        }
        return ans;
    }

    TreeNode* deserialize(string data) {
        
        if(data.size() == 0) {
            return NULL;
        }
        
        int i = 0;
        string temp = ""; 
        while(data[i] != ',') {
            temp += data[i];
            i++;
        }
        i++;
        
        TreeNode* root = new TreeNode(stoi(temp));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            
            temp = "";
            while(data[i] != ',') {
                temp += data[i];
                i++;
            }
            i++;
            
            if(temp == "#") {
                front -> left = NULL;
            }
            else {
                TreeNode* leftNode = new TreeNode(stoi(temp));
                front -> left = leftNode;
                q.push(leftNode);
            }
            
            temp = "";
            while(data[i] != ',') {
                temp += data[i];
                i++;
            }
            i++;
            
            if(temp == "#") {
                front -> right = NULL;
            }
            else {
                TreeNode* rightNode = new TreeNode(stoi(temp));
                front -> right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};
