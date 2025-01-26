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
    // Hàm duyệt sâu đệ quy để đảo ngược cây
    void dfs(TreeNode *&root)
    {
        // Tạo node tạm thời với các con trái và phải hoán đổi
        TreeNode *temp = new TreeNode(root->val, root->right, root->left);
        root = temp;

        // Đệ quy đảo ngược cây con trái nếu không phải nullptr
        if (root->left != nullptr)
            dfs(root->left);
        // Đệ quy đảo ngược cây con phải nếu không phải nullptr
        if (root->right != nullptr)
            dfs(root->right);
        return;
    }

    // Hàm chính để khởi động việc đảo ngược cây
    TreeNode *invertTree(TreeNode *root)
    {
        // Nếu cây rỗng thì trả về nullptr
        if (root == nullptr)
            return {};
        // Gọi hàm dfs để thực hiện đảo ngược
        dfs(root);
        return root;
    }
};