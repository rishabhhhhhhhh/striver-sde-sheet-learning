vector<int> levelOrder(TreeNode<int> * root){
    if(root == NULL) return {};
    vector<int> ans;
    queue< TreeNode<int>* > q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int> * current = q.front();
        q.pop();
        ans.push_back(current->data);
        if(current->left != NULL)
            q.push(current->left);
        if(current->right != NULL)
            q.push(current->right);
    }
    return ans;
}
