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
    bool dfs(TreeNode *root1, TreeNode *root2, bool &isDiff)
    {
        if (root1 == nullptr && root2 == nullptr)
        {
            return true;
        }
        if (root1 == nullptr && root2 != nullptr)
        {
            isDiff = true;
            return false;
        }
        if (root1 != nullptr && root2 == nullptr)
        {
            isDiff = true;
            return false;
        }
        if (root1->left == nullptr && root2->left != nullptr)
        {
            isDiff = true;
            return false;
        }
        if (root1->right == nullptr && root2->right != nullptr)
        {
            isDiff = true;
            return false;
        }
        if (root1->left != nullptr && root2->left == nullptr)
        {
            isDiff = true;
            return false;
        }
        if (root1->left == nullptr && root2->left != nullptr)
        {
            isDiff = true;
            return false;
        }

        cout << root1->val << " " << root2->val << "\n";
        // isDiff = false;
        if (root1->val != root2->val)
        {
            isDiff = true;
        }
        dfs(root1->left, root2->left, isDiff);
        dfs(root1->right, root2->right, isDiff);
        return (root1->val == root2->val);
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        bool isDiff = false;
        cout << dfs(p, q, isDiff);
        return isDiff == false;
    }
};