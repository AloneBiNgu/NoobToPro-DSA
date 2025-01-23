### **Valid Palindrome Solution Explanation**

Trong bài toán **Valid Palindrome**, mục tiêu là kiểm tra xem một chuỗi cho trước có phải là chuỗi đối xứng (palindrome) hay không. Chuỗi đối xứng là chuỗi đọc xuôi và đọc ngược đều giống nhau. Trong bài toán này:

1. Chuỗi có thể chứa các ký tự không phải chữ cái hoặc số, nhưng chỉ xét các ký tự chữ và số.
2. Phân biệt hoa/thường không được tính.

---

## **Đoạn mã**

### **Cách giải quyết thứ nhất**

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

### **Cách giải quyết thứ hai**

```cpp
class Solution {
public:
    bool isNormalCharacter(char c) {
        if ((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) return true;
        return false;
    }

    char toLowercase(char c) {
        if (c >= 'A' && c <= 'Z') return (char)(c - 'A' + 'a');
        return c;
    }

    bool isPalindrome(string s) {
        string temp;
        for (int i = 0; i < s.length(); i++) {
            if (isNormalCharacter(s[i]) == true) {
                temp.push_back(toLowercase(s[i]));
            }
        }

        int pointerOne = 0, pointerTwo = temp.length() - 1;
        while (pointerOne < pointerTwo) {
            if (temp[pointerOne] != temp[pointerTwo]) {
                return false;
            }

            pointerOne += 1;
            pointerTwo -= 1;
        }

        return true;
    }
};
```

---

## **Giải thích chi tiết**

### 1. **Cách giải quyết thứ nhất**

#### Hàm `convertToLowercase`

-   Nhận một tham chiếu đến ký tự (`char&`) và:
    1. Loại bỏ khoảng trắng và các ký tự không phải chữ hoặc số.
    2. Chuyển ký tự chữ in hoa thành chữ thường bằng cách tăng mã ASCII thêm 32.
    3. Trả về `true` nếu ký tự hợp lệ, ngược lại trả về `false`.

#### Hàm `isPalindrome`

-   **Bước 1:** Loại bỏ các ký tự không hợp lệ trong chuỗi bằng cách gọi `convertToLowercase`.
-   **Bước 2:** So sánh từng ký tự trong chuỗi với ký tự tương ứng từ cuối đến đầu để kiểm tra tính đối xứng.

### 2. **Cách giải quyết thứ hai**

#### Hàm `isNormalCharacter`

-   Kiểm tra xem ký tự có thuộc bảng chữ cái hoặc là ký tự số không.

#### Hàm `toLowercase`

-   Chuyển ký tự in hoa thành chữ thường bằng cách trừ mã ASCII.

#### Hàm `isPalindrome`

-   **Bước 1:** Tạo một chuỗi tạm `temp` chỉ chứa các ký tự hợp lệ, sau khi đã chuyển thành chữ thường.
-   **Bước 2:** Sử dụng hai con trỏ `pointerOne` (đầu chuỗi) và `pointerTwo` (cuối chuỗi) để kiểm tra tính đối xứng.

---

## **Phân tích độ phức tạp**

### **Thời gian**

1. **Cách 1:**

    - Làm sạch chuỗi: O(n^2) do sử dụng `erase` trong vòng lặp.
    - Kiểm tra đối xứng: O(n).
    - **Tổng cộng:** O(n^2).

2. **Cách 2:**

    - Tạo chuỗi tạm: O(n).
    - Kiểm tra đối xứng: O(n).
    - **Tổng cộng:** O(n).

### **Không gian**

1. **Cách 1:** O(1) (không sử dụng thêm không gian).
2. **Cách 2:** O(n) (sử dụng chuỗi tạm `temp`).

---

## **Tổng kết**

-   Cách giải quyết thứ hai tối ưu hơn về thời gian thực thi nhờ việc tránh sử dụng `erase` trong vòng lặp.
-   Cả hai cách đều đảm bảo tính chính xác và dễ hiểu, phù hợp để áp dụng tùy thuộc vào trường hợp cụ thể.
