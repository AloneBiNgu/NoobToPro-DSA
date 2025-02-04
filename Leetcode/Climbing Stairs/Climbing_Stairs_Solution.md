# Climbing Stairs Solution Explanation

Trong bài toán **Climbing Stairs**, mục tiêu là tìm số cách leo lên bậc thang thứ `n`, với mỗi lần có thể leo 1 hoặc 2 bậc. Đây là một bài toán điển hình về quy hoạch động (Dynamic Programming).

Dưới đây là cách tiếp cận sử dụng mảng động để tối ưu hóa việc tính toán.

---

## Cách: Sử dụng Quy Hoạch Động (Dynamic Programming)

### Mô tả

Phương pháp này sử dụng một mảng động `fb` để lưu số cách leo lên từng bậc thang, dựa trên công thức của dãy Fibonacci.

-   Nếu bạn đang ở bậc `i`, bạn có thể đến đó từ:
    -   Bậc `i - 1` (bằng cách leo 1 bậc)
    -   Bậc `i - 2` (bằng cách leo 2 bậc)

=> Số cách để leo lên bậc `i` sẽ là tổng số cách để lên `i - 1` và `i - 2`, tức là:

\[
fb[i] = fb[i - 1] + fb[i - 2]
\]

### Phức tạp thời gian và không gian

-   **Phức tạp thời gian**: O(n), vì ta duyệt qua tất cả các bậc từ `2` đến `n`.
-   **Phức tạp không gian**: O(n), vì ta sử dụng một mảng để lưu số cách leo lên từng bậc.

### Đoạn mã

```cpp
class Solution {
public:
    int climbStairs(int n) {
        vector<int> fb(n + 1); // Mảng lưu số cách leo lên từng bậc thang
        fb[0] = 1; // Cách duy nhất để đứng ở bậc 0 (không di chuyển)
        fb[1] = 1; // Chỉ có một cách để lên bậc 1 (bước 1 lần)

        for (int i = 2; i <= n; i++) { // Duyệt từ bậc 2 trở đi
            fb[i] = fb[i - 1] + fb[i - 2]; // Quy luật dãy Fibonacci
        }

        return fb[n]; // Trả về số cách leo lên bậc n
    }
};
```

---

### Giải thích

1. **Khởi tạo mảng `fb`**:

    - `fb[0] = 1`: Trạng thái cơ sở, vì khi đứng ở bậc 0, ta không cần di chuyển.
    - `fb[1] = 1`: Chỉ có một cách duy nhất để lên bậc 1 (bước một lần).

2. **Duyệt qua các bậc từ 2 đến `n`**:

    - Số cách để leo lên bậc `i` là tổng số cách leo lên `i - 1` và `i - 2`, do ta có thể đến bậc `i` bằng cách:
        - Bước 1 từ `i - 1`
        - Bước 2 từ `i - 2`

3. **Trả về `fb[n]`**, tức là số cách để lên bậc `n`.

---

## Tổng kết

-   **Phương pháp này sử dụng quy hoạch động**, giúp tối ưu hóa việc tính toán dựa trên dãy Fibonacci.
-   **Phức tạp thời gian O(n) và không gian O(n)** do sử dụng mảng `fb`.
