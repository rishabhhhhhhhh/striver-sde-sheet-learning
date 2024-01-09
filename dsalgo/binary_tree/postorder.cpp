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
vector<int> getPostOrderTraversal(TreeNode *root)
{
    if(root == NULL) {
        return {};
    }

    vector<int> ans;
    TreeNode * current = root, *prev = NULL;
    stack< TreeNode * > stk;

    while(true) {
        if(current != NULL) {
            stk.push(current);
            current = current->left;
        } else {
            if(stk.empty()) {
                break;
            } else {
                TreeNode * top = stk.top();

                if(top->right == NULL || top->right == prev) {
                    prev = top;
                    ans.push_back(top->data);
                    stk.pop();
                } else {
                    current = top->right;
                }
            }
        }
    }

    return ans;
}