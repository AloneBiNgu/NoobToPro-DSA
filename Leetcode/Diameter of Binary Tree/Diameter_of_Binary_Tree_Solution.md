## Diameter of Binary Tree Solution Explanation

Bài toán **Diameter of Binary Tree** yêu cầu tìm đường kính của cây nhị phân, tức là độ dài đường chéo dài nhất giữa hai nút bất kỳ trong cây. Để giải quyết bài toán này, chúng ta có thể sử dụng thuật toán **Depth-First Search (DFS)** để duyệt qua các nút và tính toán chiều dài của đường kính.

### Đoạn mã

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
    // Hàm đệ quy DFS để tính chiều sâu của cây và cập nhật đường kính
    int dfs(TreeNode *root, int &level) {
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
    int diameterOfBinaryTree(TreeNode *root) {
        int level = 0; // Biến lưu trữ đường kính
        dfs(root, level); // Gọi DFS để tính toán đường kính
        return level; // Trả về giá trị đường kính
    }
};
```

---

### Giải thích chi tiết

#### 1. Định nghĩa cây nhị phân

-   Mỗi nút trong cây nhị phân được định nghĩa bằng `TreeNode`, có 3 thành phần:
    -   `val`: Giá trị của nút.
    -   `left`: Con trái của nút.
    -   `right`: Con phải của nút.

#### 2. Hàm đệ quy `dfs`

-   **Mục đích:** Hàm `dfs` tính chiều sâu của cây nhị phân từ mỗi nút và cập nhật giá trị đường kính (số lượng đỉnh) tại mỗi nút.
-   **Cách thức hoạt động:**
    -   Nếu nút `root` là `nullptr`, trả về chiều sâu là `0`.
    -   Đệ quy tính chiều sâu của cây con bên trái và cây con bên phải.
    -   Tính chiều dài của đường kính tại nút hiện tại bằng cách cộng chiều sâu của cây con trái và phải. Cập nhật giá trị `level` nếu đường kính hiện tại lớn hơn `level`.
    -   Trả về chiều sâu của nút hiện tại là `1 + max(left, right)` (chiều sâu là 1 cộng với chiều sâu lớn nhất của cây con).

#### 3. Hàm `diameterOfBinaryTree`

-   **Mục đích:** Hàm này là hàm chính để tính toán đường kính của cây nhị phân.
    -   Khởi tạo biến `level` để lưu trữ đường kính của cây.
    -   Gọi hàm `dfs` để tính toán chiều sâu và cập nhật giá trị đường kính.
    -   Trả về giá trị `level` sau khi tính toán.

---

### Phân tích độ phức tạp

-   **Thời gian:**

    -   Thuật toán sử dụng phương pháp **DFS**, vì vậy mỗi nút trong cây chỉ được duyệt một lần. Số lần duyệt là `O(n)` với `n` là số lượng nút trong cây.
    -   Do đó, thời gian chạy của thuật toán là **O(n)**.

-   **Không gian:**
    -   Không gian bổ sung chủ yếu dùng cho đệ quy, tức là độ sâu của cây. Nếu cây có chiều cao `h`, không gian sẽ là **O(h)**.
    -   Trong trường hợp cây cân bằng, chiều cao sẽ là **O(log n)**. Trong trường hợp cây lệch, chiều cao sẽ là **O(n)**.

---

### Tổng kết

-   **Tư tưởng chính:** Sử dụng thuật toán DFS để tính chiều sâu của các cây con và tính toán đường kính tại mỗi nút, sau đó cập nhật đường kính lớn nhất.
-   **Ưu điểm:** Thuật toán có độ phức tạp O(n), hiệu quả cho các cây nhị phân có kích thước lớn.
-   **Nhược điểm:** Đối với cây rất lệch, thuật toán có thể gặp vấn đề về không gian do độ sâu của đệ quy.

Bằng cách sử dụng DFS, bài toán **Diameter of Binary Tree** được giải quyết một cách tối ưu và hiệu quả.
