# Lowest Common Ancestor Solution Explanation

Trong bài toán **Lowest Common Ancestor (LCA)**, mục tiêu là tìm tổ tiên chung gần nhất của hai nút trong một cây nhị phân.

## Cách tiếp cận sử dụng DFS (Depth-First Search)

### Mô tả

Phương pháp này sử dụng **DFS (Depth-First Search)** để duyệt cây và tìm tổ tiên chung gần nhất của hai nút `p` và `q`.

### Phức tạp thời gian và không gian

-   **Phức tạp thời gian**: O(N), với N là số lượng nút trong cây. Vì ta phải duyệt qua tất cả các nút trong trường hợp xấu nhất.
-   **Phức tạp không gian**: O(H), với H là chiều cao của cây (có thể lên đến O(N) nếu cây lệch, hoặc O(log N) nếu cây cân bằng).

---

## Đoạn mã

```cpp
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
```

````

---

## Giải thích thuật toán

1. **Điều kiện dừng (`base case`)**:

    - Nếu `root == nullptr`, trả về `nullptr` vì không tìm thấy gì.
    - Nếu `root == p` hoặc `root == q`, trả về chính nó vì có thể là LCA.

2. **Tìm kiếm trong cây con trái và phải**:

    - Gọi đệ quy xuống `root->left` và `root->right`.

3. **Xác định LCA**:

    - Nếu tìm thấy `p` ở một nhánh và `q` ở nhánh kia, `root` là LCA.
    - Nếu chỉ tìm thấy `p` hoặc `q` ở một phía, trả về phía đó.

4. **Trả về kết quả cuối cùng**:
    - Nếu cả hai nhánh trả về `nullptr`, nghĩa là `p` và `q` không nằm trong cây này.
    - Nếu một nhánh trả về `nullptr`, nghĩa là cả `p` và `q` đều nằm về cùng một phía của cây.

---

## Ví dụ minh họa

### Cây đầu vào

```
        3
       / \
      5   1
     / \  / \
    6   2 0  8
       / \
      7   4
```

### Trường hợp 1: Tìm LCA(5, 1)

-   DFS duyệt đến `5` và `1`, phát hiện chúng nằm ở hai nhánh khác nhau của `3`.
-   **Kết quả:** `3`

### Trường hợp 2: Tìm LCA(5, 4)

-   DFS duyệt đến `5` và `4`, thấy `4` nằm trong cây con của `5`.
-   **Kết quả:** `5`

---

## Tổng kết

-   **Phương pháp này hoạt động với bất kỳ cây nhị phân nào**, không yêu cầu cây tìm kiếm nhị phân (BST).
-   **DFS giúp duyệt cây một cách hiệu quả** và tìm ra LCA mà không cần lưu trữ thông tin phụ.

✅ Đây là cách tiếp cận tối ưu để tìm tổ tiên chung gần nhất của hai nút trong một cây nhị phân.

```

```
````
