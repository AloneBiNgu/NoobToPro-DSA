### **Valid Parentheses Solution Explanation**

Trong bài toán **Valid Parentheses**, mục tiêu là kiểm tra xem một chuỗi chỉ chứa các ký tự `(`, `)`, `[`, `]`, `{`, `}` có hợp lệ hay không. Chuỗi được xem là hợp lệ nếu:

1. Các dấu ngoặc mở được đóng đúng thứ tự.
2. Các dấu ngoặc đóng phải khớp với loại dấu ngoặc mở tương ứng.
3. Chuỗi không được chứa bất kỳ ký tự nào khác ngoài các ký tự trên.

---

## **Đoạn mã**

```cpp
class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n < 2 || n % 2 != 0) return false; // Nếu chuỗi quá ngắn hoặc có độ dài lẻ, trả về false.

        stack<char> st; // Sử dụng ngăn xếp (stack) để lưu các dấu ngoặc mở.

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]); // Đẩy dấu ngoặc mở vào ngăn xếp.
            } else {
                if (st.empty()) return false; // Nếu ngăn xếp trống, chuỗi không hợp lệ.

                char c = st.top();
                st.pop(); // Xóa dấu ngoặc mở tương ứng khỏi ngăn xếp.

                // Kiểm tra xem dấu ngoặc mở có khớp với dấu ngoặc đóng hay không.
                if ((s[i] == ')' && c != '(') ||
                    (s[i] == ']' && c != '[') ||
                    (s[i] == '}' && c != '{')) {
                    return false;
                }
            }
        }

        return st.empty(); // Chuỗi hợp lệ nếu ngăn xếp trống sau khi duyệt.
    }
};
```

---

## **Giải thích chi tiết**

### 1. **Kiểm tra điều kiện cơ bản**

-   Nếu độ dài chuỗi lẻ (`n % 2 != 0`), chắc chắn không thể hợp lệ vì không thể có đủ dấu ngoặc đóng cho tất cả dấu ngoặc mở.
-   Nếu độ dài nhỏ hơn 2, trả về `false`.

### 2. **Sử dụng ngăn xếp (stack)**

-   Ngăn xếp là cấu trúc dữ liệu phù hợp cho bài toán vì nó hoạt động theo nguyên tắc **LIFO (Last In, First Out)**.
-   Khi gặp dấu ngoặc mở `(`, `[`, `{`, ta đẩy chúng vào ngăn xếp.
-   Khi gặp dấu ngoặc đóng `)`, `]`, `}`, kiểm tra:
    -   Nếu ngăn xếp rỗng, chuỗi không hợp lệ.
    -   Nếu ngăn xếp không rỗng, kiểm tra phần tử trên đỉnh ngăn xếp. Nếu không khớp với dấu ngoặc đóng, chuỗi không hợp lệ.

### 3. **Kết luận**

-   Sau khi duyệt qua toàn bộ chuỗi, ngăn xếp phải rỗng thì chuỗi mới hợp lệ.
-   Nếu ngăn xếp còn phần tử thừa (dấu ngoặc mở chưa đóng), chuỗi không hợp lệ.

---

## **Phân tích độ phức tạp**

### **Thời gian**: **O(n)**

-   Duyệt qua toàn bộ chuỗi `s` một lần (n ký tự), mỗi thao tác `push` hoặc `pop` đều có độ phức tạp O(1).

### **Không gian**:

1. **O(n)**: Nếu sử dụng ngăn xếp để lưu trữ dấu ngoặc mở. Trong trường hợp tệ nhất, ngăn xếp có thể chứa tới n/2 dấu ngoặc mở.
2. **O(1)** (Cải tiến): Có thể sử dụng **đếm số lượng** thay vì ngăn xếp. Tuy nhiên, cách này chỉ hiệu quả khi không cần lưu thông tin chi tiết của từng dấu ngoặc.

---

## **Tổng kết**

-   Đoạn mã trên sử dụng ngăn xếp để xử lý, đảm bảo kiểm tra tính hợp lệ của chuỗi một cách rõ ràng và dễ hiểu.
-   Trong trường hợp yêu cầu tối ưu hóa bộ nhớ (O(1) không gian), ta có thể thay thế bằng cách đếm hoặc so sánh trực tiếp giữa các dấu ngoặc.
