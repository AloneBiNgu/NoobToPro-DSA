### **Best Time to Buy and Sell Stock Solution Explanation**

Trong bài toán **Max Profit** (Lợi nhuận tối đa), mục tiêu là tìm lợi nhuận lớn nhất có thể kiếm được bằng cách mua và bán cổ phiếu dựa trên giá cổ phiếu hàng ngày được cung cấp trong mảng. Quy tắc là bạn phải mua trước khi bán, và chỉ được thực hiện một giao dịch mua và bán.

---

## **Đoạn mã**

### **Phương pháp sử dụng vector**

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

### **Phương pháp tối ưu không sử dụng vector**

```cpp
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buyPrice = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (buyPrice > prices[i])
            {
                buyPrice = prices[i];
            }
            else if (prices[i] - buyPrice > profit)
            {
                profit = prices[i] - buyPrice;
            }
        }
        return profit;
    }
};
```

---

## **Giải thích chi tiết**

### 1. **Ý tưởng chính**

#### Phương pháp sử dụng vector:

-   **minPrices**: Lưu giá trị nhỏ nhất tại mỗi ngày từ ngày đầu tiên đến ngày hiện tại.
-   **maxPrices**: Lưu giá trị lớn nhất tại mỗi ngày từ ngày cuối cùng đến ngày hiện tại.
-   Sau đó, duyệt qua từng ngày để tìm lợi nhuận tối đa bằng công thức:

    ```cpp
    maxProfit = max(maxProfit, maxPrices[i] - minPrices[i]);
    ```

#### Phương pháp tối ưu:

-   Sử dụng hai biến `buyPrice` (giá mua nhỏ nhất) và `profit` (lợi nhuận lớn nhất) để theo dõi giá trị cần thiết.
-   Với mỗi ngày:
    -   Nếu giá ngày hiện tại nhỏ hơn `buyPrice`, cập nhật `buyPrice`.
    -   Nếu lợi nhuận tại ngày hiện tại (`prices[i] - buyPrice`) lớn hơn `profit`, cập nhật `profit`.

### 2. **Các bước xử lý trong mã**

#### Phương pháp sử dụng vector:

1. **Khởi tạo vector `minPrices` và `maxPrices`**:

    - `minPrices` được khởi tạo với `INT_MAX` để lưu giá trị nhỏ nhất.
    - `maxPrices` được khởi tạo với `0` để lưu giá trị lớn nhất.

2. **Tính `minPrices`**:

    - Với từng ngày `i`, `minPrices[i]` lưu giá trị nhỏ nhất từ ngày đầu tiên đến ngày `i`.

3. **Tính `maxPrices`**:

    - Với từng ngày `i`, `maxPrices[i]` lưu giá trị lớn nhất từ ngày cuối cùng đến ngày `i`.

4. **Tính lợi nhuận tối đa**:
    - Với từng ngày `i`, lợi nhuận được tính bằng hiệu giữa giá bán lớn nhất (`maxPrices[i]`) và giá mua nhỏ nhất (`minPrices[i]`).

#### Phương pháp tối ưu:

1. **Khởi tạo**:

    - Gán giá mua ban đầu (`buyPrice`) bằng giá của ngày đầu tiên.
    - Gán lợi nhuận (`profit`) là 0.

2. **Duyệt qua từng ngày**:

    - Nếu giá hiện tại nhỏ hơn `buyPrice`, cập nhật `buyPrice`.
    - Nếu lợi nhuận lớn hơn `profit`, cập nhật `profit`.

3. **Trả về**:
    - Kết quả cuối cùng là giá trị của `profit`.

---

## **Phân tích độ phức tạp**

### **Thời gian**

-   **Phương pháp sử dụng vector**: **O(n)**.
    -   Tính `minPrices` và `maxPrices`: **O(n)** mỗi vòng lặp.
    -   Tính lợi nhuận tối đa: **O(n)**.
    -   Tổng cộng: **O(n)**.
-   **Phương pháp tối ưu**: **O(n)**.
    -   Một vòng lặp duy nhất qua mảng `prices`.

### **Không gian**

-   **Phương pháp sử dụng vector**: **O(n)**.
    -   Sử dụng hai vector `minPrices` và `maxPrices`.
-   **Phương pháp tối ưu**: **O(1)**.
    -   Chỉ sử dụng hai biến `buyPrice` và `profit`.

---

## **Tổng kết**

-   **Phương pháp sử dụng vector**:
    -   Dễ hiểu và trực quan.
    -   Tuy nhiên, không gian sử dụng lớn hơn (**O(n)**).
-   **Phương pháp tối ưu**:

    -   Giải pháp hiệu quả hơn về không gian (**O(1)**).
    -   Thích hợp để xử lý các mảng `prices` lớn hơn do tiết kiệm tài nguyên.

-   Cả hai phương pháp đều đạt được độ phức tạp thời gian **O(n)**.
