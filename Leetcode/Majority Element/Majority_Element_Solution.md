## Majority Element Solution Explanation

Trong bài toán **Majority Element**, mục tiêu là tìm phần tử xuất hiện nhiều hơn nửa số lượng phần tử trong mảng. Điều này có nghĩa là phần tử đó sẽ xuất hiện ít nhất \( \frac{n}{2} \) lần trong mảng, với \( n \) là kích thước của mảng.

Dưới đây là lời giải chi tiết cho bài toán này.

## Đoạn mã

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int minAppear = n / 2;
        int left = 0, right = n - 1;

        int flag = INT_MIN;
        int result = nums[0];
        unordered_map<int, int> m;

        m[nums[(right + left) / 2]]++;
        while (left < right) {
            m[nums[left]]++;
            m[nums[right]]++;

            if (m[nums[left]] > minAppear && m[nums[left]] > flag) {
                result = nums[left];
                flag = m[nums[left]];
            }

            if (m[nums[right]] > minAppear && m[nums[right]] > flag) {
                result = nums[right];
                flag = m[nums[right]];
            }
            left++, right--;
        }

        for (auto it : m) cout << it.first << " " << it.second << "\n";
        return result;
    }
};
```

## Giải thích chi tiết

### 1. Hàm `majorityElement`

-   Hàm `majorityElement` nhận đầu vào là một mảng `nums` và trả về phần tử xuất hiện nhiều hơn nửa số lượng phần tử trong mảng.
-   Các bước thực hiện:
    -   Tính toán `minAppear` là nửa kích thước của mảng.
    -   Khởi tạo con trỏ `left` ở vị trí đầu mảng và `right` ở vị trí cuối mảng.
    -   Khởi tạo một biến `flag` với giá trị là `INT_MIN` và một biến `result` bằng phần tử đầu tiên của mảng.
    -   Duyệt qua mảng từ hai đầu vào trung gian (`left` và `right`), và sử dụng một `unordered_map` để đếm số lần xuất hiện của từng phần tử.
    -   Nếu phần tử tại vị trí `left` hoặc `right` xuất hiện nhiều hơn `minAppear` và có số lần xuất hiện lớn hơn `flag`, thì cập nhật phần tử đó làm kết quả.
    -   Cuối cùng, trả về phần tử đã tìm được.

### 2. Mảng `unordered_map`

-   Mảng `unordered_map` được sử dụng để lưu trữ số lần xuất hiện của mỗi phần tử trong mảng.
-   Việc đếm số lần xuất hiện giúp ta xác định phần tử chiếm đa số một cách hiệu quả.

### 3. Duyệt qua mảng từ hai đầu

-   Hàm thực hiện việc duyệt qua mảng từ hai đầu (`left` và `right`), tăng `left` và giảm `right` cho đến khi chúng gặp nhau.
-   Việc này giúp giảm bớt việc duyệt qua mảng không cần thiết, thay vì chỉ duyệt một lần từ đầu đến cuối.

### 4. Kết quả trả về

-   Sau khi kết thúc vòng lặp, hàm trả về phần tử `result`, đó chính là phần tử xuất hiện nhiều hơn nửa số lượng phần tử trong mảng.

## Phân tích độ phức tạp

-   **Thời gian**:

    -   Hàm duyệt qua mỗi phần tử trong mảng một lần. Vì vậy, độ phức tạp thời gian của thuật toán là O(n), với n là số lượng phần tử trong mảng.

-   **Không gian**:
    -   Mảng `unordered_map` có thể chứa tối đa `n` phần tử trong trường hợp tệ nhất (tất cả các phần tử đều khác nhau). Do đó, độ phức tạp không gian là O(n).

## Tổng kết

-   Giải pháp này sử dụng một mảng `unordered_map` để đếm số lần xuất hiện của các phần tử và tìm phần tử chiếm đa số.
-   Cách tiếp cận này hiệu quả về thời gian và không gian, và giảm bớt công việc duyệt qua mảng không cần thiết bằng cách duyệt từ hai đầu vào.
