#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    if(root == NULL) {
        return {};
    }

    stack< TreeNode* > stk;
    vector<int> ans;

    while(true) {

        if(root != NULL) {
            ans.push_back(root->data);
            stk.push(root);
            root = root->left;
        } else {
            if(stk.empty()) {
                break;
            } else {
                TreeNode * top = stk.top();
                stk.pop();

                if(top->right != NULL) {
                    root = top->right;
                }
            }
        }
    }

    return ans;
}