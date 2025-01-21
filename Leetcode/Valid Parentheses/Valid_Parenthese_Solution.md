# Valid Parentheses Solution Explanation

Trong bài toán **Valid Parentheses**, mục tiêu là kiểm tra xem một chuỗi chỉ chứa các ký tự `(`, `)`, `[`, `]`, `{`, `}` có hợp lệ hay không. Chuỗi được xem là hợp lệ nếu:

1. Các dấu ngoặc mở được đóng đúng thứ tự.
2. Các dấu ngoặc đóng phải khớp với loại dấu ngoặc mở tương ứng.
3. Chuỗi không được chứa bất kỳ ký tự nào khác ngoài các ký tự trên.

Dưới đây là lời giải chi tiết cho bài toán này:

## Đoạn mã

```cpp
class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n < 2 || n % 2 != 0) return false; // Nếu chuỗi quá ngắn hoặc có độ dài lẻ, trả về false.

        int ans = 0; // Đếm số cặp ngoặc hợp lệ.
        stack<char> st; // Sử dụng ngăn xếp (stack) để lưu các dấu ngoặc mở.

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]); // Đẩy dấu ngoặc mở vào ngăn xếp.
            }

            if (st.size() < 1) continue; // Nếu ngăn xếp trống, bỏ qua.

            if (s[i] == ')') {
                char c = st.top();
                if (c != '(') return false; // Nếu dấu ngoặc không khớp, trả về false.
                st.pop(); // Xóa dấu ngoặc mở tương ứng khỏi ngăn xếp.
                ans++;
            }
            if (s[i] == ']') {
                char c = st.top();
                if (c != '[') return false;
                st.pop();
                ans++;
            }
            if (s[i] == '}') {
                char c = st.top();
                if (c != '{') return false;
                st.pop();
                ans++;
            }
        }

        cout << ans; // In số cặp ngoặc hợp lệ (chỉ để debug).
        return ans == n / 2; // Kiểm tra nếu số cặp ngoặc hợp lệ bằng một nửa độ dài chuỗi.
    }
};
```

## Giải thích chi tiết

### 1. Kiểm tra điều kiện cơ bản

-   Chuỗi có độ dài lẻ chắc chắn không thể hợp lệ vì không thể có đủ dấu ngoặc đóng cho tất cả dấu ngoặc mở.
-   Nếu độ dài chuỗi nhỏ hơn 2, trả về `false`.

### 2. Sử dụng ngăn xếp (stack)

-   Ngăn xếp là cấu trúc dữ liệu phù hợp để xử lý các bài toán kiểu "Last In, First Out" (LIFO), đặc biệt là khi cần kiểm tra thứ tự đóng mở ngoặc.
-   Mỗi khi gặp dấu ngoặc mở `(`, `[`, `{`, ta đẩy nó vào ngăn xếp.
-   Khi gặp dấu ngoặc đóng `)`, `]`, `}`, ta kiểm tra xem ngăn xếp có trống không. Nếu trống, chuỗi không hợp lệ.
-   Nếu ngăn xếp không trống, kiểm tra xem phần tử trên đỉnh ngăn xếp có phải là dấu ngoặc mở tương ứng không:
    -   Nếu đúng, loại bỏ dấu ngoặc mở đó khỏi ngăn xếp.
    -   Nếu sai, chuỗi không hợp lệ.

### 3. Kết luận

-   Sau khi duyệt hết chuỗi, nếu số cặp ngoặc hợp lệ (`ans`) bằng một nửa độ dài chuỗi, chuỗi được xem là hợp lệ.
-   Ngược lại, nếu ngăn xếp không rỗng hoặc số cặp ngoặc không khớp, chuỗi không hợp lệ.

## Phân tích độ phức tạp

-   **Thời gian**: O(n), với n là độ dài chuỗi. Ta duyệt qua từng ký tự trong chuỗi một lần.
-   **Không gian**: O(n), do sử dụng ngăn xếp để lưu trữ các dấu ngoặc mở.

## Tổng kết

-   Phương pháp sử dụng ngăn xếp giúp đảm bảo kiểm tra tính hợp lệ của chuỗi một cách hiệu quả.
-   Đoạn mã trên xử lý tốt hầu hết các trường hợp cạnh như chuỗi rỗng, chuỗi chứa các ký tự không hợp lệ, hoặc chuỗi có thứ tự đóng mở ngoặc sai.
