# Longest Palindrome Solution Explanation

Bài toán **Longest Palindrome** yêu cầu tìm độ dài của chuỗi con dài nhất có thể được tạo từ các ký tự của chuỗi đã cho, sao cho chuỗi đó là một **palindrome** (đối xứng).

## Giải pháp: Sử dụng HashMap để đếm tần suất ký tự

### Mô tả

Giải pháp này dựa trên việc đếm số lần xuất hiện của từng ký tự trong chuỗi đầu vào. Nếu một ký tự xuất hiện **chẵn lần**, ta có thể dùng toàn bộ ký tự đó trong palindrome. Nếu một ký tự xuất hiện **lẻ lần**, ta có thể sử dụng (số lần xuất hiện - 1) ký tự đó để đảm bảo tính đối xứng và có thể chọn **một ký tự lẻ** làm trung tâm của palindrome.

### Phức tạp thời gian và không gian

-   **Phức tạp thời gian**: O(n), vì ta chỉ duyệt qua chuỗi một lần.
-   **Phức tạp không gian**: O(1), vì số lượng ký tự có thể có tối đa là 52 (26 chữ cái viết hoa + 26 chữ cái viết thường), tức là một hằng số.

---

## Đoạn mã

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hashSet; // Bảng băm để đếm tần suất ký tự
        int res = 0; // Biến lưu độ dài palindrome lớn nhất tìm được

        // Duyệt qua từng ký tự trong chuỗi để đếm số lần xuất hiện
        for (char ch : s) {
            hashSet[ch] += 1;
            // Nếu số lần xuất hiện của ký tự hiện tại là chẵn, cộng vào kết quả
            if (hashSet[ch] % 2 == 0) res += 2;
        }

        // Kiểm tra xem có ký tự nào xuất hiện lẻ lần không
        for (char ch : s) {
            if (hashSet[ch] % 2) {
                res += 1; // Có thể lấy một ký tự lẻ làm trung tâm palindrome
                break; // Chỉ cần một ký tự lẻ duy nhất
            }
        }

        return res; // Trả về độ dài palindrome lớn nhất
    }
};
```

---

## Giải thích

1. **Sử dụng HashMap (`unordered_map<char, int>`)** để đếm số lần xuất hiện của mỗi ký tự trong chuỗi.
2. **Duyệt qua từng ký tự trong chuỗi**:
    - Nếu số lần xuất hiện của ký tự đó trở thành **chẵn**, ta cộng 2 vào kết quả (`res += 2`).
    - Điều này đảm bảo rằng tất cả các ký tự có số lần xuất hiện chẵn đều có thể đóng góp vào palindrome.
3. **Xử lý ký tự lẻ**:
    - Duyệt lại chuỗi, nếu tồn tại một ký tự có số lần xuất hiện **lẻ**, ta có thể sử dụng nó làm trung tâm của palindrome (**cộng thêm 1 vào `res`**).
    - Ta chỉ cần lấy **một ký tự lẻ duy nhất**, nên chỉ cần kiểm tra ký tự đầu tiên xuất hiện lẻ và `break` sau khi cộng 1.
4. **Trả về độ dài palindrome lớn nhất có thể tạo được**.

---

## Tổng kết

-   **Thuật toán đơn giản và hiệu quả**, chỉ duyệt qua chuỗi **hai lần**.
-   **Không gian tối ưu** vì số lượng ký tự là hằng số (**O(1)**).
-   **Ưu điểm**:
    -   Xây dựng nhanh chóng bằng HashMap.
    -   Xử lý tốt các chuỗi có số lượng lớn ký tự.
    -   Tận dụng tính chất chẵn/lẻ để tối ưu hóa độ dài palindrome.

**Có thể áp dụng tương tự cho các bài toán liên quan đến phân tích tần suất ký tự trong chuỗi.**
