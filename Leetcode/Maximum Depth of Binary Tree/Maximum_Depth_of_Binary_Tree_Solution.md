## Maximum Depth of Binary Tree Solution Explanation

Bài toán **Maximum Depth of Binary Tree** yêu cầu tìm chiều sâu (hoặc độ cao) của cây nhị phân. Chiều sâu của cây là số lượng các đỉnh từ nút gốc đến nút xa nhất. Thuật toán này có thể được giải quyết thông qua phương pháp **Đệ quy** (Recursion).

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
    // Hàm đệ quy để tính chiều sâu của cây nhị phân
    int dfs(TreeNode* root, int depth = 1) {
        // Nếu nút con là nullptr, trả về chiều sâu hiện tại
        if (root == nullptr) return depth;

        // Đệ quy tính chiều sâu của cây con bên trái và bên phải
        int left = dfs(root->left, depth + 1);
        int right = dfs(root->right, depth + 1);

        // Trả về chiều sâu lớn nhất giữa cây con trái và cây con phải
        return max(left, right);
    }

    // Hàm chính tính chiều sâu của cây nhị phân
    int maxDepth(TreeNode* root) {
        return dfs(root, 1) - 1;  // Trừ 1 để chiều sâu đúng
    }
};
```

---

### Giải thích chi tiết

#### 1. Định nghĩa cây nhị phân

-   Mỗi nút trong cây nhị phân được định nghĩa bằng `TreeNode`, có 3 thành phần:
    -   `val`: Giá trị của nút.
    -   `left`: Con trỏ đến cây con bên trái.
    -   `right`: Con trỏ đến cây con bên phải.

#### 2. Hàm đệ quy `dfs`

-   **Mục đích:** Hàm `dfs` tính chiều sâu của cây nhị phân từ một nút cụ thể.
-   **Cách thức hoạt động:**
    -   Nếu nút `root` là `nullptr`, tức là đã đến cuối cây (hoặc cây trống), trả về chiều sâu hiện tại.
    -   Nếu nút hiện tại không phải là `nullptr`, ta đệ quy tính chiều sâu của cây con bên trái và bên phải.
    -   Sau đó, chúng ta so sánh chiều sâu của cây con trái và phải, và trả về chiều sâu lớn hơn (chiều sâu của nhánh sâu nhất).

#### 3. Hàm `maxDepth`

-   **Mục đích:** Hàm này là hàm chính để tính chiều sâu của cây nhị phân.
    -   Gọi hàm đệ quy `dfs` từ nút gốc (`root`) và truyền vào giá trị chiều sâu bắt đầu là `1`.
    -   Sau khi tính toán, hàm trả về kết quả chiều sâu trừ đi `1` để làm cho chiều sâu đúng, vì hàm `dfs` bắt đầu đếm từ `1` thay vì `0`.

---

### Phân tích độ phức tạp

-   **Thời gian:**

    -   Thuật toán duyệt qua toàn bộ cây một lần, với mỗi nút chỉ được duyệt một lần, do đó thời gian chạy của thuật toán là **O(n)**, với `n` là số lượng nút trong cây.

-   **Không gian:**
    -   Thuật toán sử dụng đệ quy, vì vậy không gian sử dụng chủ yếu phụ thuộc vào chiều cao của cây. Trong trường hợp cây là cây cân bằng, không gian đệ quy sẽ là **O(log n)**. Nếu cây lệch, không gian sẽ là **O(n)**.

---

### Tổng kết

-   **Tư tưởng chính:** Dùng thuật toán đệ quy để duyệt qua các nút và tính chiều sâu của cây từ mỗi nút. Sau đó, trả về chiều sâu của nhánh sâu nhất.
-   **Ưu điểm:** Thuật toán dễ hiểu và đơn giản, với độ phức tạp thời gian là **O(n)**.
-   **Nhược điểm:** Đối với cây rất lệch, thuật toán có thể gặp vấn đề về không gian do độ sâu của đệ quy.

Bằng cách sử dụng phương pháp đệ quy, bài toán **Maximum Depth of Binary Tree** có thể được giải quyết một cách hiệu quả và dễ dàng.
