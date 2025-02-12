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
    // Hàm đệ quy để tính chiều sâu của cây nhị phân
    int dfs(TreeNode *root, int depth = 1)
    {
        // Nếu nút con là nullptr, trả về chiều sâu hiện tại
        if (root == nullptr)
            return depth;

        // Đệ quy tính chiều sâu của cây con bên trái và bên phải
        int left = dfs(root->left, depth + 1);
        int right = dfs(root->right, depth + 1);

        // Trả về chiều sâu lớn nhất giữa cây con trái và cây con phải
        return max(left, right);
    }

    // Hàm chính tính chiều sâu của cây nhị phân
    int maxDepth(TreeNode *root)
    {
        return dfs(root, 1) - 1; // Trừ 1 để chiều sâu đúng
    }
};
