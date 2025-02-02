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
    /**
     * Hàm dfs (Depth-First Search) để kiểm tra độ cao của từng node và xác định xem cây có cân bằng không.
     * Nếu phát hiện bất kỳ node nào có sự chênh lệch độ cao > 1, trả về -1 để báo hiệu cây không cân bằng.
     *
     * @param root - con trỏ đến node gốc của cây hoặc cây con.
     * @return int - nếu cây cân bằng, trả về chiều cao của cây con. Nếu không, trả về -1.
     */
    int dfs(TreeNode *root)
    {
        // Nếu node hiện tại là nullptr, trả về chiều cao là 0.
        if (root == nullptr)
            return 0;

        // Đệ quy kiểm tra chiều cao của cây con bên trái.
        int left = dfs(root->left);
        // Nếu cây con bên trái không cân bằng, trả về -1.
        if (left == -1)
            return -1;

        // Đệ quy kiểm tra chiều cao của cây con bên phải.
        int right = dfs(root->right);
        // Nếu cây con bên phải không cân bằng, trả về -1.
        if (right == -1)
            return -1;

        // Nếu sự chênh lệch giữa hai cây con lớn hơn 1, trả về -1 (cây không cân bằng).
        if (abs(left - right) > 1)
            return -1;

        // Nếu cây cân bằng, trả về chiều cao của node hiện tại.
        return max(left, right) + 1;
    }

    /**
     * Hàm kiểm tra xem một cây nhị phân có cân bằng chiều cao hay không.
     *
     * @param root - con trỏ đến node gốc của cây.
     * @return bool - true nếu cây cân bằng, false nếu không.
     */
    bool isBalanced(TreeNode *root)
    {
        // Gọi hàm dfs để kiểm tra chiều cao và tính trạng cân bằng của cây.
        // Nếu kết quả trả về là -1, nghĩa là cây không cân bằng, trả về false.
        return dfs(root) != -1;
    }
};
