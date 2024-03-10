vector<int> leftView(Node *root) {
    vector<int> ans;
    
    if(root == NULL) {
        return ans;
    }
    
    Node *prev = NULL, *current;
    queue< Node* > q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        current = q.front();
        q.pop();
        
        if(current == NULL) {
            if(!q.empty()) {
                q.push(NULL);
            }
        } else {
            if(prev == NULL) {
                ans.push_back(current->data);
            }
        }
        
        if(current && current->left) {
            q.push(current->left);
        }
        if(current && current->right) {
            q.push(current->right);
        }
        
        prev = current;
    }
    return ans;
}
