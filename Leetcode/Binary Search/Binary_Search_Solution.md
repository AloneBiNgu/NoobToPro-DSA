# Binary Search Solution Explanation

Bài toán **Binary Search** yêu cầu tìm kiếm một phần tử trong một mảng đã được sắp xếp theo thứ tự tăng dần. Dưới đây là cách giải và lời giải thích chi tiết.

## Mô tả

Phương pháp này sử dụng thuật toán **tìm kiếm nhị phân**, chia mảng thành hai phần và kiểm tra giá trị mục tiêu (`target`) nằm ở phần nào. Quy trình này được lặp lại cho đến khi tìm được giá trị hoặc xác định giá trị không tồn tại trong mảng.

### Đoạn mã

```cpp
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = (right + left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                left++;
            else
                right--;
        }

        return -1;
    }
};
```

### Giải thích

1. **Khởi tạo biến**:

    - `left`: chỉ số bắt đầu của mảng, ban đầu là 0.
    - `right`: chỉ số cuối của mảng, ban đầu là kích thước của mảng (`nums.size()`).

2. **Vòng lặp**:

    - Trong mỗi vòng lặp, chỉ số giữa (`mid`) được tính bằng công thức `(left + right) / 2`.
    - Nếu giá trị tại `nums[mid]` bằng `target`, trả về chỉ số `mid`.
    - Nếu `nums[mid] < target`, giá trị mục tiêu nằm ở nửa bên phải mảng, nên tăng `left`.
    - Ngược lại, nếu `nums[mid] > target`, giá trị mục tiêu nằm ở nửa bên trái mảng, nên giảm `right`.

3. **Kết thúc**:
    - Nếu không tìm thấy `target`, trả về `-1`.

### Phân tích thuật toán

-   **Phức tạp thời gian**: O(log n)
    -   Ở mỗi bước, mảng được chia đôi, do đó số lượng bước giảm theo cấp số nhân.
-   **Phức tạp không gian**: O(1)
    -   Không sử dụng bộ nhớ phụ trợ ngoài các biến tạm thời.

### Lưu ý

Đoạn mã trên có lỗi nhỏ:

-   Trong trường hợp `nums[mid] < target`, cần cập nhật `left = mid + 1` thay vì `left++`.
-   Trong trường hợp `nums[mid] > target`, cần cập nhật `right = mid` thay vì `right--`.

### Đoạn mã sửa lỗi

```cpp
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = (right + left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }

        return -1;
    }
};
```

## Tổng kết

-   **Binary Search** là thuật toán hiệu quả để tìm kiếm trong mảng đã sắp xếp với độ phức tạp thời gian là O(log n).
-   Đảm bảo cập nhật đúng giá trị `left` và `right` trong mỗi bước để tránh lỗi logic.

Thuật toán này thích hợp cho các bài toán yêu cầu tìm kiếm nhanh trên tập dữ liệu lớn đã được sắp xếp.
