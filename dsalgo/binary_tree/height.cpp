int findHeight(TreeNode<int> *root) {
    if(root==NULL)return 0;
    int leftHeight=findHeight(root->left);
    int rightHeight=findHeight(root->right);
    return 1+max(leftHeight,rightHeight);
}
