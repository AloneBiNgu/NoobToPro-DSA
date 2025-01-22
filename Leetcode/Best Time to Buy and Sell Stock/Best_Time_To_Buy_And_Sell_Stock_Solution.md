### **Best Time to Buy and Sell Stock Solution Explanation**

Trong bài toán **Max Profit** (Lợi nhuận tối đa), mục tiêu là tìm lợi nhuận lớn nhất có thể kiếm được bằng cách mua và bán cổ phiếu dựa trên giá cổ phiếu hàng ngày được cung cấp trong mảng. Quy tắc là bạn phải mua trước khi bán, và chỉ được thực hiện một giao dịch mua và bán.

---

## **Đoạn mã**

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // Khởi tạo hai vector để lưu giá trị nhỏ nhất và lớn nhất theo từng ngày
        vector<int> minPrices(n, INT_MAX), maxPrices(n, 0);

        // Tính giá trị nhỏ nhất cho từng ngày từ trái sang phải
        for (int i = 0; i < n; i++) {
            minPrices[i] = i == 0 ? prices[i] : min(minPrices[i - 1], prices[i]);
        }

        // Tính giá trị lớn nhất cho từng ngày từ phải sang trái
        for (int i = n - 1; i >= 0; i--) {
            maxPrices[i] = i == n - 1 ? prices[i] : max(maxPrices[i + 1], prices[i]);
        }

        // Tính lợi nhuận tối đa
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, maxPrices[i] - minPrices[i]);
        }

        return maxProfit;
    }
};
```

---

## **Giải thích chi tiết**

### 1. **Ý tưởng chính**

-   **minPrices**: Lưu giá trị nhỏ nhất tại mỗi ngày từ ngày đầu tiên đến ngày hiện tại.
-   **maxPrices**: Lưu giá trị lớn nhất tại mỗi ngày từ ngày cuối cùng đến ngày hiện tại.
-   Sau đó, duyệt qua từng ngày để tìm lợi nhuận tối đa bằng công thức:

    ```
    maxProfit = max(maxProfit, maxPrices[i] - minPrices[i]);
    ```

    Công thức này so sánh giá bán lớn nhất và giá mua nhỏ nhất tại cùng một thời điểm.

### 2. **Các bước xử lý trong mã**

1. **Khởi tạo vector minPrices và maxPrices**:

    - `minPrices` được khởi tạo với `INT_MAX` để lưu giá trị nhỏ nhất.
    - `maxPrices` được khởi tạo với `0` để lưu giá trị lớn nhất.

2. **Tính minPrices**:

    - Với từng ngày `i`, `minPrices[i]` sẽ lưu giá trị nhỏ nhất từ ngày đầu tiên đến ngày `i`.
    - Công thức:
        ```cpp
        minPrices[i] = i == 0 ? prices[i] : min(minPrices[i - 1], prices[i]);
        ```

3. **Tính maxPrices**:

    - Với từng ngày `i`, `maxPrices[i]` sẽ lưu giá trị lớn nhất từ ngày cuối cùng đến ngày `i`.
    - Công thức:
        ```cpp
        maxPrices[i] = i == n - 1 ? prices[i] : max(maxPrices[i + 1], prices[i]);
        ```

4. **Tính lợi nhuận tối đa**:
    - Với từng ngày `i`, lợi nhuận được tính bằng hiệu giữa giá bán lớn nhất (`maxPrices[i]`) và giá mua nhỏ nhất (`minPrices[i]`).
    - Công thức:
        ```cpp
        maxProfit = max(maxProfit, maxPrices[i] - minPrices[i]);
        ```

### 3. **Kiểm tra các trường hợp đặc biệt**

-   Nếu mảng `prices` rỗng hoặc có ít hơn 2 phần tử, thì không thể thực hiện giao dịch. Trong trường hợp này, kết quả là `0`.
-   Đảm bảo rằng giá mua phải nhỏ hơn giá bán.

---

## **Phân tích độ phức tạp**

### **Thời gian**: **O(n)**

-   Vòng lặp đầu tiên: Tính `minPrices` trong **O(n)**.
-   Vòng lặp thứ hai: Tính `maxPrices` trong **O(n)**.
-   Vòng lặp cuối: Tính lợi nhuận tối đa trong **O(n)**.
-   Tổng cộng: **O(n)**.

### **Không gian**: **O(n)**

-   Sử dụng hai vector `minPrices` và `maxPrices` để lưu giá trị nhỏ nhất và lớn nhất tương ứng.
-   Tổng không gian phụ thuộc là **O(n)**.

---

## **Tổng kết**

-   Đoạn mã trên là một giải pháp đơn giản và dễ hiểu cho bài toán tìm lợi nhuận tối đa khi mua và bán cổ phiếu một lần.
-   Nếu yêu cầu tối ưu hóa không gian xuống **O(1)**, bạn có thể tính toán trực tiếp mà không cần dùng vector. Hãy để tôi biết nếu bạn cần cải tiến này!
