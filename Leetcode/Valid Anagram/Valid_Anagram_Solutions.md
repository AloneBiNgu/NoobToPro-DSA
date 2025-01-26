# Anagram Solution Explanation

Trong bài toán **Anagram**, mục tiêu là kiểm tra xem hai chuỗi có phải là hoán vị của nhau (anagram) hay không. Dưới đây là hai cách giải phổ biến cho bài toán này.

## Cách 1: Dùng hai map để đếm tần suất ký tự

### Mô tả

Phương pháp này sử dụng hai bản đồ (map) để đếm số lần xuất hiện của các ký tự trong từng chuỗi. Sau đó, so sánh tần suất của các ký tự giữa hai chuỗi.

### Độ phức tạp

-   **Thời gian**: O(n), với n là độ dài của chuỗi.
-   **Không gian**: O(k), với k là số lượng ký tự duy nhất trong chuỗi (tối đa 256 ký tự cho ASCII).

### Đoạn mã

```cpp
class Solution
{
public:
    // Hàm kiểm tra xem hai chuỗi có phải là anagram của nhau hay không
    bool isAnagram(string s, string t)
    {
        // Nếu độ dài hai chuỗi khác nhau, chắc chắn không phải anagram
        if (s.length() != t.length())
            return false;

        // Sử dụng hai bản đồ (map) để đếm số lần xuất hiện của các ký tự trong hai chuỗi
        map<int, int> m1, m2;

        // Duyệt qua từng ký tự trong chuỗi s và tăng giá trị tương ứng trong map m1
        for (char c : s)
        {
            m1[(int)c] += 1; // (int)c chuyển ký tự sang mã ASCII để làm key
        }

        // Duyệt qua từng ký tự trong chuỗi t và tăng giá trị tương ứng trong map m2
        for (char c : t)
        {
            m2[(int)c] += 1; // Tương tự như trên
        }

        // Kiểm tra từng ký tự trong chuỗi t
        for (char c : t)
        {
            // Nếu số lần xuất hiện của ký tự trong m1 khác m2, không phải anagram
            if (m1[(int)c] != m2[(int)c])
                return false;
        }

        // Nếu tất cả các kiểm tra đều đạt, hai chuỗi là anagram
        return true;
    }
};
```

### Giải thích

1. Sử dụng hai bản đồ để lưu trữ tần suất ký tự cho hai chuỗi.
2. So sánh từng ký tự giữa hai bản đồ. Nếu bất kỳ tần suất nào khác nhau, kết luận không phải anagram.

## Cách 2: Dùng một unordered_map để tối ưu

### Mô tả

Phương pháp này sử dụng một `unordered_map` để đếm tần suất ký tự, với các thao tác tăng và giảm giá trị trong cùng một bản đồ khi duyệt qua hai chuỗi. Cuối cùng, kiểm tra xem tất cả giá trị trong map có bằng 0 hay không.

### Độ phức tạp

-   **Thời gian**: O(n), với n là độ dài của chuỗi.
-   **Không gian**: O(k), với k là số lượng ký tự duy nhất trong chuỗi.

### Đoạn mã

```cpp
class Solution {
public:
    // Hàm kiểm tra xem hai chuỗi có phải là anagram của nhau hay không
    bool isAnagram(string s, string t) {
        // Nếu độ dài hai chuỗi khác nhau, chắc chắn không phải anagram
        if (s.length() != t.length()) return false;

        // Sử dụng `unordered_map` để đếm số lần xuất hiện của các ký tự
        unordered_map<int, int> m;

        // Duyệt qua từng ký tự trong chuỗi `s`, tăng số lần xuất hiện trong map
        for (char c : s) {
            m[c]++;
        }

        // Duyệt qua từng ký tự trong chuỗi `t`, giảm số lần xuất hiện trong map
        for (char c : t) {
            m[c]--;
        }

        // Kiểm tra giá trị trong map:
        // Nếu bất kỳ giá trị nào không bằng 0, hai chuỗi không phải là anagram
        for (auto it : m) {
            if (it.second != 0) return false;
        }

        // Nếu tất cả các kiểm tra đều đạt, hai chuỗi là anagram
        return true;
    }
};
```

### Giải thích

1. Duyệt qua từng ký tự trong chuỗi `s` để tăng tần suất.
2. Duyệt qua từng ký tự trong chuỗi `t` để giảm tần suất.
3. Cuối cùng, kiểm tra trong bản đồ. Nếu tất cả giá trị đều bằng 0, hai chuỗi là anagram.

## Tổng kết

-   **Cách 1** sử dụng hai bản đồ để lưu tần suất ký tự. Đây là cách dễ hiểu nhưng tốn thêm bộ nhớ.
-   **Cách 2** chỉ sử dụng một `unordered_map`, giúp tối ưu bộ nhớ và hiệu suất hơn so với cách 1.

Cả hai cách đều trả về kết quả chính xác. Chọn cách phù hợp tùy thuộc vào yêu cầu và giới hạn của bài toán.
