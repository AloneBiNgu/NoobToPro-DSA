# Reverse Linked List Solution Explanation

Bài toán **Reverse Linked List** yêu cầu đảo ngược một danh sách liên kết đơn (singly-linked list). Dưới đây là một cách giải sử dụng phương pháp **lặp (iterative method)**, giúp đạt độ phức tạp tối ưu O(n).

## Giải pháp: Duyệt qua danh sách và đảo chiều từng nút

### Mô tả

Thuật toán hoạt động bằng cách duyệt qua từng nút của danh sách liên kết, đảo ngược hướng liên kết bằng cách thay đổi con trỏ `next` của từng nút, cho đến khi danh sách được đảo ngược hoàn toàn.

### Phức tạp thời gian và không gian

-   **Phức tạp thời gian**: O(n), vì cần duyệt qua toàn bộ danh sách một lần.
-   **Phức tạp không gian**: O(1), vì chỉ sử dụng một số biến tạm thời để hỗ trợ hoán đổi liên kết.

### Đoạn mã

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head; // Nếu danh sách rỗng, trả về nullptr

        ListNode *node = nullptr; // Biến lưu trữ node mới sau khi đảo ngược

        // Duyệt qua từng phần tử trong danh sách
        while (head != nullptr) {
            ListNode *temp = head->next; // Lưu lại node tiếp theo để tiếp tục duyệt
            head->next = node; // Đảo chiều liên kết: trỏ node hiện tại về node trước đó
            node = head; // Cập nhật node mới đã đảo ngược
            head = temp; // Di chuyển con trỏ head tới node tiếp theo
        }

        return node; // Trả về node mới đầu tiên (tức là node cuối cùng ban đầu)
    }
};
```

### Giải thích thuật toán

1. **Kiểm tra danh sách rỗng**: Nếu `head` là `nullptr`, ta trả về `nullptr` ngay lập tức.
2. **Sử dụng con trỏ `node`**: Ban đầu được đặt là `nullptr`, sẽ giữ giá trị của node đầu tiên sau khi danh sách bị đảo ngược.
3. **Duyệt danh sách liên kết**:
    - Lưu node tiếp theo (`temp = head->next`) để không bị mất liên kết.
    - Đảo chiều liên kết của node hiện tại (`head->next = node`).
    - Cập nhật node mới (`node = head`).
    - Di chuyển `head` đến node tiếp theo (`head = temp`).
4. **Trả về node đầu tiên của danh sách đã đảo ngược**.

## Tổng kết

-   **Thuật toán lặp giúp tối ưu bộ nhớ** vì chỉ sử dụng các biến tạm (`node` và `temp`).
-   **Thời gian thực thi nhanh với O(n)** vì chỉ cần một vòng lặp duyệt danh sách.
-   **Dễ đọc, dễ triển khai** và có thể mở rộng cho các biến thể như đảo ngược một phần danh sách.

Nếu cần áp dụng cho các bài toán tương tự, chỉ cần thay đổi cách kiểm soát liên kết hoặc điều kiện kết thúc vòng lặp.
