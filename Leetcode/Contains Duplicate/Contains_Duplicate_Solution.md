## Contains Duplicate Explaintion Solution

Bài toán **Contains Duplicate** yêu cầu kiểm tra xem trong một mảng có bất kỳ phần tử nào lặp lại hay không. Cách giải quyết hiệu quả nhất là sử dụng cấu trúc dữ liệu **HashMap** (hay `unordered_map` trong C++) để theo dõi số lần xuất hiện của các phần tử trong mảng.

### Đoạn mã

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashMap; // Sử dụng unordered_map để lưu trữ số lần xuất hiện của từng phần tử
        for (auto i : nums) { // Duyệt qua từng phần tử trong mảng
            hashMap[i]++; // Tăng số lần xuất hiện của phần tử i
            if (hashMap[i] > 1) // Nếu phần tử xuất hiện lần thứ hai, trả về true
                return true;
        }
        return false; // Nếu không có phần tử nào bị trùng, trả về false
    }
};
```

---

### Giải thích chi tiết

#### 1. Định nghĩa cấu trúc dữ liệu

-   **unordered_map<int, int> hashMap**: Cấu trúc dữ liệu này dùng để lưu trữ mỗi phần tử trong mảng `nums` và số lần xuất hiện của chúng. `unordered_map` có thời gian tra cứu trung bình là O(1), giúp chúng ta kiểm tra sự tồn tại của phần tử một cách nhanh chóng.

#### 2. Duyệt qua mảng `nums`

-   **for (auto i : nums)**: Duyệt qua từng phần tử `i` trong mảng `nums`.
    -   **hashMap[i]++**: Tăng số lần xuất hiện của phần tử `i` trong `hashMap`. Nếu phần tử này chưa xuất hiện trước đó, `hashMap[i]` sẽ được gán giá trị `1`.
    -   **if (hashMap[i] > 1)**: Kiểm tra xem phần tử `i` có xuất hiện lần thứ hai không. Nếu có, tức là mảng có phần tử trùng lặp, trả về `true`.

#### 3. Trả về kết quả

-   Nếu không có phần tử nào xuất hiện hơn một lần, vòng lặp kết thúc và hàm trả về `false`.

---

### Phân tích độ phức tạp

-   **Thời gian:**

    -   Thời gian duyệt qua mảng là **O(n)**, với `n` là số lượng phần tử trong mảng.
    -   Mỗi thao tác truy xuất và chèn vào `unordered_map` có độ phức tạp trung bình là **O(1)**.
    -   Vì vậy, tổng độ phức tạp thời gian của thuật toán là **O(n)**.

-   **Không gian:**
    -   Thuật toán sử dụng một `unordered_map` để lưu trữ các phần tử và số lần xuất hiện của chúng, vì vậy không gian bổ sung là **O(n)**, với `n` là số lượng phần tử trong mảng.

---

### Tổng kết

-   **Tư tưởng chính:** Sử dụng `unordered_map` để theo dõi số lần xuất hiện của mỗi phần tử trong mảng, nếu một phần tử xuất hiện nhiều hơn một lần thì trả về `true`, ngược lại trả về `false`.
-   **Ưu điểm:** Thuật toán có độ phức tạp thời gian là **O(n)**, hiệu quả cho các mảng lớn.
-   **Nhược điểm:** Độ phức tạp không gian là **O(n)**, vì phải lưu trữ các phần tử trong `unordered_map`.

Bằng cách sử dụng `unordered_map`, bài toán **Contains Duplicate** được giải quyết nhanh chóng và hiệu quả.
