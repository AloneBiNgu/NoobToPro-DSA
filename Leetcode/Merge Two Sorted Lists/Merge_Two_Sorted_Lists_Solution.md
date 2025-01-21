# Merge Two Sorted Lists Solution Explanation

Trong bài toán **Merge Two Sorted Lists**, mục tiêu là hợp nhất hai danh sách liên kết đã được sắp xếp sao cho danh sách kết quả vẫn được sắp xếp. Dưới đây là lời giải chi tiết sử dụng cách tiếp cận cơ bản.

## Đoạn mã

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

class Solution
{
public:
    // Hàm chèn một nút mới có giá trị `val` vào cuối danh sách liên kết
    void insert(ListNode *&head, int val)
    {
        // Tạo một nút mới với giá trị `val`
        ListNode *newNode = new ListNode();
        newNode->val = val;
        newNode->next = nullptr;

        // Nếu danh sách hiện tại rỗng (hoặc head có giá trị mặc định là 0), gán nút mới làm head
        if (head->val == 0)
        {
            head = newNode;
            return;
        }

        // Tìm nút cuối cùng trong danh sách liên kết
        ListNode *last = head;
        while (last->next != nullptr)
        {
            last = last->next;
        }

        // Gắn nút mới vào cuối danh sách
        last->next = newNode;
    };

    // Hàm trộn hai danh sách liên kết đã được sắp xếp
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        vector<int> tempArray; // Mảng tạm thời để lưu trữ các giá trị từ cả hai danh sách
        ListNode *result = new ListNode(); // Danh sách liên kết kết quả

        // Duyệt qua danh sách liên kết `list1` và thêm các giá trị vào mảng tạm thời
        ListNode *temp = list1;
        while (temp != nullptr)
        {
            tempArray.push_back(temp->val);
            temp = temp->next;
        }

        // Duyệt qua danh sách liên kết `list2` và thêm các giá trị vào mảng tạm thời
        temp = list2;
        while (temp != nullptr)
        {
            tempArray.push_back(temp->val);
            temp = temp->next;
        }

        // Nếu không có giá trị nào trong cả hai danh sách, trả về danh sách rỗng
        if (tempArray.size() == 0)
        {
            return {};
        }

        // Sắp xếp các giá trị trong mảng theo thứ tự tăng dần
        sort(tempArray.begin(), tempArray.end());

        // Tạo lại danh sách liên kết từ mảng đã được sắp xếp
        for (auto it : tempArray)
        {
            insert(result, it);
        }

        return result; // Trả về danh sách liên kết đã được trộn và sắp xếp
    }
};
```

## Giải thích chi tiết

### 1. Hàm `insert`

-   Hàm `insert` được sử dụng để thêm một giá trị mới vào danh sách liên kết.
-   Nếu danh sách hiện tại rỗng (hoặc `head` là nullptr), một nút mới sẽ được tạo và trở thành `head`.
-   Nếu danh sách không rỗng, nút mới sẽ được thêm vào cuối danh sách.

### 2. Hàm `mergeTwoLists`

#### **Thu thập dữ liệu từ hai danh sách**:

-   Duyệt qua từng danh sách `list1` và `list2`, thêm tất cả các giá trị vào một mảng tạm `tempArray`.

#### **Sắp xếp mảng**:

-   Mảng `tempArray` được sắp xếp để đảm bảo các giá trị theo thứ tự tăng dần.

#### **Tạo danh sách liên kết kết quả**:

-   Duyệt qua mảng đã sắp xếp, sử dụng hàm `insert` để thêm từng giá trị vào danh sách liên kết kết quả `result`.

#### **Trả về danh sách liên kết kết quả**:

-   Hàm trả về danh sách liên kết đã được hợp nhất.

## Phân tích độ phức tạp

-   **Thời gian**:

    -   Duyệt qua hai danh sách: O(n + m), với n và m lần lượt là độ dài của `list1` và `list2`.
    -   Sắp xếp mảng: O((n + m) \* log(n + m)).
    -   Thêm các phần tử vào danh sách liên kết: O(n + m).
    -   **Tổng**: O((n + m) \* log(n + m)).

-   **Không gian**:
    -   Sử dụng mảng tạm để lưu trữ tất cả các giá trị: O(n + m).
    -   Bộ nhớ cho danh sách liên kết kết quả: O(n + m).
    -   **Tổng**: O(n + m).

## Tổng kết

-   Cách tiếp cận này sử dụng mảng tạm và sắp xếp để hợp nhất hai danh sách liên kết. Mặc dù dễ hiểu và đơn giản, cách làm này không phải là tối ưu nhất về hiệu suất.
-   Có thể cải thiện bằng cách sử dụng hai con trỏ để hợp nhất danh sách ngay trong quá trình duyệt, giảm độ phức tạp xuống O(n + m).
