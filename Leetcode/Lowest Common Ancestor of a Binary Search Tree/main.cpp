/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    /**
     * Hàm đệ quy tìm kiếm tổ tiên chung gần nhất (LCA) của hai nút p và q.
     * @param root - Nút hiện tại trong quá trình duyệt cây.
     * @param p - Nút đầu tiên cần tìm LCA.
     * @param q - Nút thứ hai cần tìm LCA.
     * @return Con trỏ tới nút LCA hoặc nullptr nếu không tìm thấy.
     */
    TreeNode *dfs(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // Nếu root là nullptr, không có gì để tìm kiếm
        if (root == nullptr)
            return nullptr;

        // Nếu root chính là một trong hai nút p hoặc q, trả về root vì nó có thể là LCA
        if (root == p || root == q)
            return root;

        // Tìm kiếm trong cây con bên trái
        TreeNode *left = dfs(root->left, p, q);

        // Tìm kiếm trong cây con bên phải
        TreeNode *right = dfs(root->right, p, q);

        // Nếu tìm thấy p và q ở cả hai nhánh trái & phải, root chính là LCA
        if (left != nullptr && right != nullptr)
            return root;

        // Nếu chỉ tìm thấy ở một phía, trả về phía đó (nút p hoặc q hoặc LCA đã tìm thấy trước đó)
        return (left != nullptr) ? left : right;
    }

    /**
     * Hàm chính để tìm tổ tiên chung gần nhất của hai nút p và q.
     * @param root - Gốc của cây nhị phân.
     * @param p - Nút đầu tiên.
     * @param q - Nút thứ hai.
     * @return Con trỏ tới LCA của p và q.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return dfs(root, p, q);
    }
};
