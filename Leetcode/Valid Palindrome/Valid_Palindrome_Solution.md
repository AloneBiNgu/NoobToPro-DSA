### **Valid Palindrome Solution Explanation**

Trong bài toán **Valid Palindrome**, mục tiêu là kiểm tra xem một chuỗi cho trước có phải là chuỗi đối xứng (palindrome) hay không. Chuỗi đối xứng là chuỗi đọc xuôi và đọc ngược đều giống nhau. Trong bài toán này:

1. Chuỗi có thể chứa các ký tự không phải chữ cái hoặc số, nhưng chỉ xét các ký tự chữ và số.
2. Phân biệt hoa/thường không được tính.

---

## **Đoạn mã**

```cpp
class Solution {
public:
    // Hàm chuyển ký tự thành chữ thường và kiểm tra tính hợp lệ
    bool convertToLowercase(char& c) {
        int asciiCode = (int)c; // Lấy mã ASCII của ký tự

        // Loại bỏ ký tự khoảng trắng
        if (asciiCode == 32) return false;

        // Chuyển ký tự in hoa thành chữ thường
        if (asciiCode >= 65 && asciiCode <= 90) {
            c = (char)(asciiCode + 32);
            return true;
        }

        // Giữ nguyên ký tự số
        if (asciiCode >= 48 && asciiCode <= 57) return true;

        // Loại bỏ các ký tự không hợp lệ
        if (asciiCode < 97 || asciiCode > 122) {
            return false;
        } else {
            return true;
        }

        return false;
    }

    // Hàm kiểm tra chuỗi có phải là palindrome hay không
    bool isPalindrome(string s) {
        // Loại bỏ các ký tự không hợp lệ bằng cách sử dụng convertToLowercase
        while (true) {
            bool flag = true;
            for (int i = 0; i < s.size(); i++) {
                if (convertToLowercase(s[i]) == false) {
                    flag = false;
                    s.erase(s.begin() + i); // Xóa ký tự không hợp lệ
                }
            }
            if (flag == true) break; // Thoát vòng lặp khi chuỗi chỉ còn ký tự hợp lệ
        }

        // Kiểm tra tính đối xứng của chuỗi
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != s[s.size() - (1 + i)]) return false;
        }

        return true;
    }
};
```

---

## **Giải thích chi tiết**

### 1. **Hàm `convertToLowercase`**

-   Hàm này nhận một tham chiếu đến ký tự (`char&`) và:
    1. Loại bỏ khoảng trắng và các ký tự không phải chữ hoặc số.
    2. Chuyển ký tự chữ in hoa thành chữ thường bằng cách tăng mã ASCII thêm 32.
    3. Trả về `true` nếu ký tự hợp lệ, ngược lại trả về `false`.

### 2. **Hàm `isPalindrome`**

#### Bước 1: Làm sạch chuỗi

-   Sử dụng vòng lặp `while` để loại bỏ các ký tự không hợp lệ trong chuỗi bằng cách gọi `convertToLowercase`.
-   Xóa các ký tự không hợp lệ bằng phương thức `erase`.
-   Thoát vòng lặp khi không còn ký tự nào cần xóa.

#### Bước 2: Kiểm tra tính đối xứng

-   So sánh từng ký tự trong chuỗi với ký tự tương ứng từ cuối đến đầu.
-   Nếu có ký tự không khớp, trả về `false`.
-   Nếu tất cả các ký tự khớp, chuỗi là palindrome.

---

## **Phân tích độ phức tạp**

### **Thời gian**: **O(n)**

1. Làm sạch chuỗi:
    - Duyệt qua chuỗi nhiều lần để loại bỏ ký tự không hợp lệ (trung bình O(n)).
2. Kiểm tra đối xứng:
    - So sánh các ký tự từ đầu và cuối (O(n)).
3. Tổng cộng: **O(n)**.

### **Không gian**: **O(1)**

-   Không sử dụng cấu trúc dữ liệu bổ sung, chỉ thao tác trực tiếp trên chuỗi.

---

## **Tổng kết**

-   Giải pháp trên là một cách tiếp cận dễ hiểu để kiểm tra tính đối xứng của chuỗi bằng cách làm sạch chuỗi trước.
-   Nếu cần tối ưu hoặc viết gọn hơn, có thể sử dụng hai con trỏ để so sánh trực tiếp mà không cần loại bỏ ký tự.
