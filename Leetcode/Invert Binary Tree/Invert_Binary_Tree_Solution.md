# Invert Binary Tree Solution Explanation

Trong bài toán **Invert Binary Tree**, mục tiêu là đảo ngược một cây nhị phân sao cho cây kết quả hoắt động như ảnh phản chiếu của cây ban đầu. Dưới đây là lời giải chi tiết.

## Đoạn mã

```cpp
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
    void dfs(TreeNode *&root)
    {
        TreeNode *temp = new TreeNode(root->val, root->right, root->left);
        root = temp;

        if (root->left != nullptr)
            dfs(root->left);
        if (root->right != nullptr)
            dfs(root->right);
        return;
    }

    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        dfs(root);
        return root;
    }
};
```

## Giải thích chi tiết

### 1. Hàm `dfs`

-   Hàm `dfs` được sử dụng để duyệt qua các node của cây nhị phân và hoán đổi các con trái và phải của mỗi node.
-   Tại mỗi bước:
    -   Tạo một node tạm thời với giá trị hiện tại của node gốc và hoán đổi các con của nó.
    -   Gán node gốc hiện tại bằng node tạm thời mới tạo.
-   Đệ quy thực hiện trên con trái và con phải nếu chúng không phải là `nullptr`.

### 2. Hàm `invertTree`

-   Hàm `invertTree` là điểm khởi đầu để đảo ngược cây.
-   Nếu cây rỗng (node gốc `root` là `nullptr`), trả về một cây rỗng.
-   Gọi hàm `dfs` để thực hiện đảo ngược toàn bộ cây và trả về node gốc mới.

## Phân tích độ phức tạp

-   **Thời gian**:

    -   Duyệt qua mỗi node trong cây đúng một lần, vì vậy độ phức tạp là O(n), với n là số lượng node trong cây.

-   **Không gian**:
    -   Sử dụng bộ nhớ ngăn xếp cho các lời gọi đệ quy. Trong trường hợp tệ nhất (cây lệch), chiều sâu của cây là O(h), với h là chiều cao của cây.

## Tổng kết

-   Cách tiếp cận này sử dụng đệ quy để đảo ngược cây nhị phân. Đây là một giải pháp đơn giản, trực quan và hiệu quả.
-   Có thể tối ưu hơn bằng cách sử dụng cách duyệt cây không đệ quy để giảm thiểu độ sâu của ngăn xếp.
