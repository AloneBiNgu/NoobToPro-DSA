## Add Binary Solution Explanation

Trong bài toán **Add Binary**, mục tiêu là cộng hai số nhị phân và trả về kết quả dưới dạng chuỗi nhị phân. Số nhị phân được biểu diễn dưới dạng chuỗi, và chúng ta cần thực hiện phép cộng như trong toán học, với phép mang (carry) khi tổng của hai bit vượt quá 1.

Dưới đây là lời giải chi tiết cho bài toán này.

## Đoạn mã

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        // Khởi tạo chỉ số cho hai chuỗi a và b, bắt đầu từ vị trí cuối cùng của mỗi chuỗi
        int i = a.length() - 1, j = b.length() - 1;

        // Khởi tạo biến carry để lưu trữ giá trị mang, bắt đầu từ 0
        int carry = 0;

        // Khởi tạo chuỗi result để lưu trữ kết quả cuối cùng
        string result;

        // Lặp cho đến khi cả hai chuỗi được duyệt hết hoặc còn mang (carry)
        while (i >= 0 || j >= 0 || carry == 1) {
            // Nếu còn bit ở chuỗi a, cộng giá trị tại vị trí i vào carry
            if (i >= 0) {
                carry += a[i] - '0';  // '0' được trừ để chuyển ký tự thành số
                i--;  // Di chuyển chỉ số i sang trái
            }

            // Nếu còn bit ở chuỗi b, cộng giá trị tại vị trí j vào carry
            if (j >= 0) {
                carry += b[j] - '0';  // '0' được trừ để chuyển ký tự thành số
                j--;  // Di chuyển chỉ số j sang trái
            }

            // Thêm kết quả của phép cộng vào chuỗi result
            // carry % 2 cho ra kết quả tại vị trí hiện tại (0 hoặc 1)
            result += (carry % 2) + '0';  // Chuyển từ số sang ký tự

            // Cập nhật carry cho vòng lặp tiếp theo
            carry /= 2;  // Chia mang cho 2 để đưa carry sang vị trí kế tiếp
        }

        // Đảo ngược chuỗi kết quả để có thứ tự đúng
        reverse(result.begin(), result.end());

        // Trả về kết quả cuối cùng
        return result;
    }
};
```

## Giải thích chi tiết

### 1. Hàm `addBinary`

-   Hàm `addBinary` nhận vào hai chuỗi nhị phân `a` và `b` và trả về một chuỗi kết quả là tổng của chúng.
-   Các bước thực hiện:
    -   Khởi tạo các chỉ số `i` và `j` lần lượt là chỉ số cuối của chuỗi `a` và `b`.
    -   Khởi tạo biến `carry` bằng 0, dùng để lưu trữ giá trị mang trong phép cộng.
    -   Khởi tạo chuỗi `result` để lưu trữ kết quả cuối cùng.
    -   Duyệt qua các chuỗi từ cuối đến đầu (tương tự phép cộng tay), cộng các bit tại các vị trí `i` và `j`, đồng thời xử lý mang (carry) nếu cần.

### 2. Vòng lặp cộng nhị phân

-   Vòng lặp tiếp tục khi một trong các điều kiện sau thỏa mãn:
    -   Chỉ số `i` chưa vượt quá đầu chuỗi `a`.
    -   Chỉ số `j` chưa vượt quá đầu chuỗi `b`.
    -   Còn mang (carry).
-   Trong mỗi vòng lặp, ta cộng bit tại vị trí `i` của `a` và `j` của `b` vào giá trị mang. Sau đó, tính toán tổng tại vị trí đó và thêm kết quả vào chuỗi `result`.

### 3. Phép mang (carry)

-   Sau mỗi phép cộng, giá trị mang sẽ được tính toán bằng `carry / 2` và tổng tại vị trí hiện tại sẽ là `carry % 2`.
-   Điều này giúp đảm bảo rằng kết quả cộng nhị phân được thực hiện chính xác, giống như trong toán học, khi tổng vượt quá 1, ta phải mang 1 sang bit kế tiếp.

### 4. Đảo ngược chuỗi kết quả

-   Sau khi tính toán xong kết quả, chuỗi `result` chứa kết quả theo thứ tự ngược lại (do chúng ta cộng từ cuối chuỗi). Do đó, ta sử dụng hàm `reverse` để đảo ngược chuỗi và trả về kết quả cuối cùng.

### 5. Kết quả trả về

-   Sau khi kết thúc vòng lặp, hàm trả về chuỗi `result`, đó chính là tổng của hai chuỗi nhị phân.

## Phân tích độ phức tạp

-   **Thời gian**:
    -   Vòng lặp duyệt qua các phần tử trong chuỗi `a` và `b`. Mỗi chuỗi được duyệt một lần, do đó độ phức tạp thời gian là O(max(n, m)), trong đó `n` và `m` là độ dài của chuỗi `a` và `b`.
-   **Không gian**:
    -   Chuỗi kết quả có độ dài tối đa là `max(n, m) + 1` trong trường hợp có mang ở bit cao nhất. Do đó, độ phức tạp không gian là O(max(n, m)).

## Tổng kết

-   Giải pháp này sử dụng một vòng lặp để cộng hai chuỗi nhị phân từ phải sang trái, xử lý mang và xây dựng kết quả cuối cùng.
-   Cách tiếp cận này rất hiệu quả và đơn giản, thực hiện phép cộng nhị phân mà không cần chuyển đổi sang số nguyên.
