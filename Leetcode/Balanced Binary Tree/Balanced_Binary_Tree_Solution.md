Dựa vào format của file **Invert_Binary_Tree_Solution.md**, tôi sẽ tạo một solution tương tự cho bài toán **Balanced Binary Tree** dựa trên đoạn code bạn cung cấp.

---

# Balanced Binary Tree Solution Explanation

Trong bài toán **Balanced Binary Tree**, mục tiêu là xác định xem một cây nhị phân có cân bằng chiều cao hay không. Một cây nhị phân được coi là **cân bằng** nếu chênh lệch chiều cao giữa cây con bên trái và cây con bên phải của **bất kỳ** node nào không vượt quá 1.

Dưới đây là lời giải chi tiết.

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
class Solution {
public:
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = dfs(root->left);
        if (left == -1) return -1;
        int right = dfs(root->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};
```

## Giải thích chi tiết

### 1. Hàm `dfs(TreeNode* root)`

-   Hàm `dfs` (Depth-First Search) được sử dụng để tính toán chiều cao của mỗi node trong cây.
-   Tại mỗi node:
    -   Nếu node là `nullptr`, trả về 0.
    -   Tính chiều cao của cây con bên trái (`left`).
        -   Nếu cây con bên trái không cân bằng (`left == -1`), trả về `-1` ngay lập tức.
    -   Tính chiều cao của cây con bên phải (`right`).
        -   Nếu cây con bên phải không cân bằng (`right == -1`), trả về `-1`.
    -   Nếu chênh lệch giữa `left` và `right` lớn hơn 1, trả về `-1`, báo hiệu cây không cân bằng.
    -   Nếu cây vẫn cân bằng, trả về chiều cao của node hiện tại: `max(left, right) + 1`.

### 2. Hàm `isBalanced(TreeNode* root)`

-   Hàm `isBalanced` gọi `dfs(root)`.
-   Nếu giá trị trả về khác `-1`, cây được coi là cân bằng (`true`).
-   Nếu giá trị trả về là `-1`, cây không cân bằng (`false`).

## Phân tích độ phức tạp

-   **Thời gian**:

    -   Mỗi node chỉ được duyệt đúng một lần, nên độ phức tạp là **O(n)**, với `n` là số lượng node trong cây.

-   **Không gian**:
    -   Sử dụng bộ nhớ ngăn xếp cho các lời gọi đệ quy.
    -   Trong trường hợp tốt nhất (cây cân bằng hoàn hảo), chiều sâu của ngăn xếp là **O(log n)**.
    -   Trong trường hợp tệ nhất (cây lệch hoàn toàn), chiều sâu là **O(n)**.

## Tổng kết

-   Cách tiếp cận này sử dụng **duyệt sâu (DFS) kết hợp với kiểm tra chiều cao** để xác định cây có cân bằng hay không.
-   Giải pháp này hiệu quả vì mỗi node chỉ được truy cập đúng một lần thay vì tính chiều cao lặp lại nhiều lần.
-   Đây là một cách tiếp cận **tối ưu** so với phương pháp tính chiều cao cho từng node riêng lẻ.
