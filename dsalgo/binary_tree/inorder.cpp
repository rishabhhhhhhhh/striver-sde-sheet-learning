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
vector<int> getInOrderTraversal(TreeNode *root)
{
    if(root == NULL) {
        return {};
    }

    stack< TreeNode* > stk;
    TreeNode * current = root;
    vector<int> ans;

    while(true) {

        if(current != NULL) {

            stk.push(current);
            current = current->left;

        } else {

            if(stk.empty()) {
                break;
            } else {
                TreeNode * top = stk.top();
                stk.pop();

                ans.push_back(top->data);
                
                if(top->right != NULL) {
                    current = top->right;
                }
            }
        }
    }

    return ans;
}