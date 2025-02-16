/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void dfs(TreeNode *left, TreeNode *right, bool &isMirror)
    {
        if (left == nullptr && right != nullptr)
        {
            isMirror = false;
            return;
        }
        if (left != nullptr && right == nullptr)
        {
            isMirror = false;
            return;
        }
        if (left == nullptr && right == nullptr)
        {
            return;
        }

        if (left->left != nullptr && right->right == nullptr)
            isMirror = false;
        if (left->left == nullptr && right->right != nullptr)
            isMirror = false;
        if (left->right != nullptr && right->left == nullptr)
            isMirror = false;
        if (left->right == nullptr && right->left != nullptr)
            isMirror = false;

        if (left->val != right->val)
            isMirror = false;
        dfs(left->left, right->right, isMirror);
        dfs(left->right, right->left, isMirror);
        return;
    }
    bool isSymmetric(TreeNode *root)
    {
        bool isMirror = true;
        dfs(root->left, root->right, isMirror);
        return isMirror == true;
    }
};