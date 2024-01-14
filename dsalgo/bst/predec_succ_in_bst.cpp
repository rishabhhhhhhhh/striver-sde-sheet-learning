void traversal(TreeNode * root, int key, pair<int, int> & ans) {

    if(root != NULL) {
        traversal(root->left, key, ans);
        if(root->data < key)
            ans.first = max(ans.first, root->data);
        else if(root->data > key)
            ans.second = min(ans.second, root->data);
        traversal(root->right, key, ans);
    }
}
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    pair<int, int> ans = {INT_MIN, INT_MAX}; 
    traversal(root, key, ans);
    if(ans.first == INT_MIN)
        ans.first = -1;
    if(ans.second == INT_MAX)
        ans.second = -1;
    return ans;
}