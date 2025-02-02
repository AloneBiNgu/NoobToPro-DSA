# Has Cycle in Linked List Solution Explanation

Trong bài toán **Has Cycle in Linked List**, mục tiêu là xác định xem danh sách liên kết có chứa chu kỳ hay không. Dưới đây là ba phương pháp tiếp cận khác nhau.

## Đoạn mã

### **Cách 1: Sử dụng Hash Table để phát hiện chu kỳ**

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_map>

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;
        std::unordered_map<ListNode *, int> hashTable;

        while (true)
        {
            hashTable[head] += 1; // Đánh dấu số lần truy cập node
            if (hashTable[head] >= 2) // Nếu truy cập lần thứ hai, có chu kỳ
                return true;
            if (head->next == nullptr)
                break; // Nếu đến cuối danh sách mà không lặp lại node, không có chu kỳ
            ListNode *temp = head->next;
            head->next = nullptr; // Ngắt liên kết để tránh lặp vô tận
            head = temp;
        }
        return false;
    }
};
```

#### **Giải thích:**

-   Sử dụng `unordered_map` để lưu trữ các node đã duyệt qua.
-   Nếu một node bị truy cập hai lần, danh sách có chu kỳ.
-   Nếu `head->next` là `nullptr`, danh sách không có chu kỳ.

#### **Phân tích độ phức tạp:**

-   **Thời gian:** O(n) vì cần duyệt từng node một lần.
-   **Không gian:** O(n) do lưu trữ thông tin của từng node trong `unordered_map`.

---

### **Cách 2: Sử dụng Hash Table tối ưu hơn (cải tiến Cách 1)**

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_map>

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;
        std::unordered_map<ListNode *, int> hashTable;
        hashTable[head] += 1; // Đánh dấu node đầu tiên

        while (true)
        {
            if (head->next == nullptr)
                return false; // Nếu đến cuối danh sách, không có chu kỳ

            hashTable[head->next] += 1; // Đánh dấu node tiếp theo

            if (hashTable[head->next] >= 2)
                return true; // Nếu node đã xuất hiện lần thứ hai, có chu kỳ

            head = head->next; // Di chuyển đến node tiếp theo
        }
        return false;
    }
};
```

#### **Giải thích:**

-   Cách này tối ưu hơn Cách 1 vì không cần thay đổi `head->next = nullptr`.
-   Cũng sử dụng `unordered_map` để theo dõi số lần xuất hiện của mỗi node.

#### **Phân tích độ phức tạp:**

-   **Thời gian:** O(n).
-   **Không gian:** O(n).

---

### **Cách 3: Thuật toán Two Pointers (Hai con trỏ chậm và nhanh)**

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next != nullptr)
        {
            fast = fast->next->next; // Di chuyển fast 2 bước
            slow = slow->next;       // Di chuyển slow 1 bước

            if (fast == slow) // Nếu fast gặp slow, có chu kỳ
                return true;
        }
        return false; // Nếu duyệt hết danh sách mà không gặp nhau, không có chu kỳ
    }
};
```

#### **Giải thích:**

-   Sử dụng hai con trỏ:
    -   **Slow pointer**: Di chuyển từng bước một.
    -   **Fast pointer**: Di chuyển hai bước một.
-   Nếu hai con trỏ gặp nhau, danh sách có chu kỳ.
-   Nếu `fast` hoặc `fast->next` là `nullptr`, danh sách không có chu kỳ.

#### **Phân tích độ phức tạp:**

-   **Thời gian:** O(n) (trong trường hợp tệ nhất, `fast` mất tối đa O(n) bước để gặp `slow`).
-   **Không gian:** O(1) (không sử dụng bộ nhớ bổ sung).

---

## **Tổng kết**

| Phương pháp                                        | Độ phức tạp thời gian | Độ phức tạp không gian | Ưu điểm                       | Nhược điểm                      |
| -------------------------------------------------- | --------------------- | ---------------------- | ----------------------------- | ------------------------------- |
| **Cách 1** (Hash Table - chỉnh sửa liên kết)       | O(n)                  | O(n)                   | Dễ hiểu, triển khai đơn giản  | Làm thay đổi cấu trúc danh sách |
| **Cách 2** (Hash Table - không chỉnh sửa liên kết) | O(n)                  | O(n)                   | Giữ nguyên cấu trúc danh sách | Tốn thêm bộ nhớ                 |
| **Cách 3** (Hai con trỏ Floyd)                     | O(n)                  | O(1)                   | Không tốn bộ nhớ phụ          | Khó hiểu hơn hai cách trên      |

-   Nếu cần tối ưu về bộ nhớ, **Cách 3** là lựa chọn tốt nhất.
-   Nếu cần giải pháp dễ hiểu hơn, có thể dùng **Cách 2**.
-   Nếu có thể thay đổi danh sách liên kết trong quá trình kiểm tra, **Cách 1** cũng là một lựa chọn.
