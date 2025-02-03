# MyQueue Solution Explanation

Trong bài toán **MyQueue**, mục tiêu là tạo ra một hàng đợi (queue) sử dụng cấu trúc dữ liệu `unordered_map` để lưu trữ các phần tử. Dưới đây là lời giải chi tiết về cách cài đặt một hàng đợi với các thao tác như thêm phần tử vào hàng đợi, xóa phần tử khỏi hàng đợi, và kiểm tra các thao tác cơ bản.

## Đoạn mã

```cpp
class MyQueue {
private:
    unordered_map<int, int> st; // Dùng unordered_map để lưu trữ các phần tử trong hàng đợi.

public:
    // Hàm khởi tạo MyQueue
    MyQueue() {
    }

    // Hàm thêm phần tử vào hàng đợi
    void push(int x) {
        st[st.size()] = x; // Thêm phần tử `x` vào cuối hàng đợi, với chỉ số là kích thước hiện tại của unordered_map.
        cout << "Push command:\n";

        // In ra trạng thái hiện tại của hàng đợi
        for (int i = 0; i < st.size(); i++) {
            cout << st[i] << " ";
        }
        cout << "\n";
    }

    // Hàm xóa phần tử khỏi đầu hàng đợi và trả về phần tử đó
    int pop() {
        cout << "Pop command:\n";
        int result = st[0]; // Lấy phần tử ở vị trí đầu tiên
        // Di chuyển tất cả các phần tử phía sau lên một vị trí phía trước
        for (int i = 0; i < st.size() - 1; i++) {
            st[i] = st[i + 1];
        }
        st.erase(st.size() - 1); // Xóa phần tử cuối cùng (vì nó đã bị di chuyển)

        // In ra trạng thái hiện tại của hàng đợi
        for (int i = 0; i < st.size(); i++) {
            cout << st[i] << " ";
        }
        cout << "\n";
        return result; // Trả về phần tử đã bị loại bỏ
    }

    // Hàm xem phần tử đầu tiên trong hàng đợi mà không xóa nó
    int peek() {
        return st[0]; // Trả về phần tử đầu tiên trong hàng đợi
    }

    // Hàm kiểm tra xem hàng đợi có rỗng không
    bool empty() {
        return (st.size() == 0); // Nếu kích thước hàng đợi bằng 0 thì trả về true, nghĩa là hàng đợi rỗng
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```

## Giải thích chi tiết

### 1. Khởi tạo hàng đợi

-   `unordered_map<int, int> st;`: Dùng `unordered_map` để lưu trữ các phần tử trong hàng đợi. Mỗi phần tử có một chỉ số riêng (dựa trên kích thước của map) và giá trị là phần tử thực tế trong hàng đợi.

### 2. Hàm `push`

-   Thêm một phần tử vào cuối hàng đợi bằng cách gán `st[st.size()] = x`. Kích thước hiện tại của `unordered_map` được dùng làm chỉ số cho phần tử.
-   Sau khi thêm, trạng thái của hàng đợi được in ra để người dùng có thể thấy hàng đợi hiện tại.

### 3. Hàm `pop`

-   Lấy phần tử đầu tiên trong hàng đợi và lưu trữ vào biến `result`.
-   Sau đó, di chuyển tất cả các phần tử phía sau lên một vị trí phía trước để giữ cho các phần tử trong hàng đợi luôn liên tiếp từ vị trí 0.
-   Sau khi di chuyển, phần tử cuối cùng sẽ bị xóa.
-   Trả về phần tử đã bị loại bỏ và in ra trạng thái của hàng đợi sau khi thao tác.

### 4. Hàm `peek`

-   Trả về phần tử đầu tiên trong hàng đợi mà không xóa nó.

### 5. Hàm `empty`

-   Kiểm tra xem hàng đợi có rỗng hay không bằng cách so sánh kích thước của `unordered_map` với 0.

## Phân tích độ phức tạp

-   **Thời gian**:

    -   Hàm `push`: O(1) vì thao tác thêm phần tử vào cuối chỉ đơn giản là gán giá trị vào chỉ số hiện tại của `unordered_map`.
    -   Hàm `pop`: O(n) vì phải di chuyển tất cả các phần tử từ vị trí đầu lên vị trí trước đó, với n là số phần tử hiện có trong hàng đợi.
    -   Hàm `peek`: O(1) vì chỉ cần trả về phần tử đầu tiên mà không cần thao tác gì thêm.
    -   Hàm `empty`: O(1) vì chỉ cần kiểm tra kích thước của `unordered_map`.

-   **Không gian**:

    -   Chúng ta sử dụng `unordered_map` để lưu trữ các phần tử trong hàng đợi. Không gian sử dụng là O(n), với n là số lượng phần tử trong hàng đợi.

## Tổng kết

-   Đây là một cài đặt đơn giản của một hàng đợi bằng cách sử dụng `unordered_map`. Mặc dù `unordered_map` có thể hiệu quả trong nhiều trường hợp, nhưng cách cài đặt này không phải là tối ưu nhất cho hàng đợi vì thao tác `pop` có độ phức tạp O(n). Một cách hiệu quả hơn có thể sử dụng `queue` trong thư viện chuẩn của C++ hoặc một cấu trúc dữ liệu khác như deque.
