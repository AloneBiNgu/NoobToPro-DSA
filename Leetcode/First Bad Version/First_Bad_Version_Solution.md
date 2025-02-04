# First Bad Version Solution Explanation

Trong bài toán **First Bad Version**, mục tiêu là tìm ra phiên bản đầu tiên bị lỗi trong một dãy các phiên bản. Chúng ta có thể sử dụng API `isBadVersion(int version)` để kiểm tra xem một phiên bản cụ thể có bị lỗi hay không. Để giải quyết bài toán một cách hiệu quả, chúng ta sử dụng thuật toán **Binary Search** (Tìm kiếm nhị phân).

## Đoạn mã

```cpp
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n; // Giới hạn tìm kiếm từ phiên bản 1 đến phiên bản n
        int badVersion = n; // Giả sử phiên bản xấu nhất là phiên bản cuối cùng

        while (left < right) {
            long long mid = ((long long)right + (long long)left - 1) / 2;
            // Tìm phiên bản ở giữa bằng cách lấy trung bình cộng để tránh tràn số

            if (isBadVersion(mid)) { // Nếu mid là phiên bản lỗi
                badVersion = min(badVersion, (int)mid); // Cập nhật badVersion với giá trị nhỏ nhất
                right = mid; // Tiếp tục tìm kiếm về bên trái
            } else {
                left = mid + 1; // Nếu mid không phải là phiên bản lỗi, tìm kiếm về bên phải
            }
        }

        return badVersion; // Trả về phiên bản lỗi đầu tiên tìm được
    }
};
```

---

## Giải thích chi tiết

### 1. Khởi tạo biến

-   `left = 1`, `right = n`: Chúng ta giới hạn khoảng tìm kiếm từ phiên bản `1` đến `n`.
-   `badVersion = n`: Giả sử ban đầu phiên bản lỗi đầu tiên là `n` (trường hợp tệ nhất).

### 2. Tìm kiếm nhị phân

-   **Bước 1:** Tìm giá trị trung bình `mid = (left + right - 1) / 2`.
-   **Bước 2:** Kiểm tra xem `mid` có phải là phiên bản lỗi bằng `isBadVersion(mid)`.

    -   Nếu **mid bị lỗi**, nghĩa là phiên bản lỗi đầu tiên có thể nằm ở `mid` hoặc trước đó. Chúng ta cập nhật `badVersion` và tiếp tục tìm kiếm ở khoảng `[left, mid]`.
    -   Nếu **mid không bị lỗi**, nghĩa là phiên bản lỗi đầu tiên nằm ở phía bên phải, ta cập nhật `left = mid + 1`.

-   **Lặp lại quá trình** cho đến khi `left >= right`, khi đó `badVersion` sẽ lưu phiên bản lỗi đầu tiên.

---

## Phân tích độ phức tạp

-   **Thời gian:**

    -   Chúng ta đang sử dụng thuật toán **tìm kiếm nhị phân**, vì vậy số lần lặp lại của vòng lặp là `O(log n)`.
    -   Ở mỗi lần lặp, chúng ta kiểm tra `isBadVersion(mid)`, và vì đây là một phép toán O(1), nên tổng thể thuật toán chạy trong **O(log n)**.

-   **Không gian:**
    -   Chỉ sử dụng một số biến nguyên (`left`, `right`, `badVersion`, `mid`), nên không gian bổ sung là **O(1)**.

---

## Tổng kết

-   **Tư tưởng chính:** Dùng **tìm kiếm nhị phân** để thu hẹp phạm vi tìm kiếm, tránh kiểm tra từng phiên bản một cách tuyến tính.
-   **Ưu điểm:** Giải thuật có độ phức tạp O(log n), nhanh hơn nhiều so với kiểm tra từng phiên bản một cách tuần tự (O(n)).
-   **Nhược điểm:** Cần chú ý khi tính toán `mid` để tránh tràn số khi `n` rất lớn.

Bằng cách áp dụng phương pháp tìm kiếm nhị phân, bài toán được giải quyết một cách tối ưu và hiệu quả.
