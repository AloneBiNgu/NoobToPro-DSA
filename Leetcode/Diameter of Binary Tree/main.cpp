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
    // Hàm đệ quy DFS để tính chiều sâu của cây và cập nhật đường kính
    int dfs(TreeNode *root, int &level)
    {
        // Nếu nút con rỗng, trả về chiều sâu 0
        if (root == nullptr)
            return 0;

        // Đệ quy tính chiều sâu của cây con bên trái và bên phải
        int left = dfs(root->left, level);
        int right = dfs(root->right, level);

        // Cập nhật đường kính bằng cách lấy chiều dài của đường chéo đi qua nút hiện tại
        level = max(level, left + right);

        // Trả về chiều sâu của nút hiện tại (1 + chiều sâu cây con sâu nhất)
        return 1 + max(left, right);
    }

    // Hàm chính tính toán đường kính của cây nhị phân
    int diameterOfBinaryTree(TreeNode *root)
    {
        int level = 0;    // Biến lưu trữ đường kính
        dfs(root, level); // Gọi DFS để tính toán đường kính
        return level;     // Trả về giá trị đường kính
    }
};
