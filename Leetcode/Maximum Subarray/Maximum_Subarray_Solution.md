# Maximum Subarray Solution Explanation

Bài toán **Maximum Subarray** yêu cầu tìm tổng lớn nhất của một dãy con liên tiếp trong mảng số nguyên đã cho. Dưới đây là một cách giải phổ biến cho bài toán này sử dụng thuật toán Kadane, với thời gian chạy tối ưu là O(n).

## Giải pháp: Thuật toán Kadane

### Mô tả

Thuật toán Kadane tìm dãy con liên tiếp có tổng lớn nhất bằng cách duyệt qua từng phần tử trong mảng và tính tổng dần. Nếu tổng hiện tại trở nên âm, ta đặt lại tổng về 0. Đồng thời, ta luôn kiểm tra để cập nhật kết quả lớn nhất.

### Phức tạp thời gian và không gian

-   **Phức tạp thời gian**: O(n), vì chỉ duyệt qua mảng một lần.
-   **Phức tạp không gian**: O(1), vì chỉ sử dụng thêm các biến tạm.

### Đoạn mã

```cpp
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // Nếu mảng chỉ có một phần tử, trả về chính phần tử đó
        if (nums.size() == 1)
            return nums[0];

        int total = 0;          // Tổng hiện tại của dãy con
        int result = nums[0];  // Tổng lớn nhất tìm được

        // Duyệt qua từng phần tử trong mảng
        for (int i = 0; i < nums.size(); i++)
        {
            // Nếu tổng hiện tại < 0, đặt lại tổng về 0
            if (total < 0)
            {
                total = 0;
            }

            // Cộng phần tử hiện tại vào tổng
            total += nums[i];

            // Cập nhật kết quả nếu tổng hiện tại lớn hơn tổng lớn nhất
            result = max(result, total);
        }

        return result; // Trả về tổng lớn nhất
    }
};
```

### Giải thích

1. **Xử lý trường hợp đặc biệt**: Nếu mảng chỉ có một phần tử, dãy con lớn nhất chính là phần tử đó.
2. **Biến `total`**: Dùng để theo dõi tổng hiện tại của dãy con.
    - Nếu `total` trở nên âm, đặt lại giá trị của nó về 0 vì không có ý nghĩa tiếp tục cộng thêm giá trị âm.
3. **Biến `result`**: Lưu trữ giá trị tổng lớn nhất tìm được cho đến hiện tại.
    - Cập nhật giá trị của `result` mỗi khi `total` vượt qua giá trị cũ của `result`.
4. **Duyệt qua mảng**: Dùng vòng lặp duyệt qua tất cả các phần tử trong mảng, thực hiện cộng dồn vào `total` và so sánh để cập nhật `result`.

## Tổng kết

-   Thuật toán Kadane là giải pháp tối ưu để giải bài toán này với độ phức tạp thời gian O(n).
-   Bằng cách kiểm tra và đặt lại tổng khi cần thiết, ta có thể tìm được tổng lớn nhất mà không cần xét tất cả các dãy con, giúp tiết kiệm thời gian.
-   **Ưu điểm**: Dễ triển khai, hiệu quả với mảng có kích thước lớn.

Nếu cần áp dụng thuật toán này cho các bài toán tương tự, chỉ cần thay đổi logic kiểm tra tổng và cập nhật giá trị theo yêu cầu bài toán.
