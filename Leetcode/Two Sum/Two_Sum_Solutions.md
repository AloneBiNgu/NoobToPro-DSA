
# Two Sum Solution Explanation

Trong bài toán **Two Sum**, mục tiêu là tìm ra hai chỉ số trong mảng sao cho tổng của hai phần tử tại các chỉ số đó bằng một giá trị mục tiêu (target). Dưới đây là hai cách giải phổ biến cho bài toán này.

## Cách 1: Dùng hai vòng lặp (Brute Force)

### Mô tả

Phương pháp này sử dụng hai vòng lặp để kiểm tra tất cả các cặp phần tử trong mảng và tìm ra cặp nào có tổng bằng `target`.

### Phức tạp thời gian và không gian
- **Phức tạp thời gian**: O(n^2), vì ta phải kiểm tra tất cả các cặp trong mảng.
- **Phức tạp không gian**: O(1), vì không sử dụng bộ nhớ phụ trợ ngoài các biến tạm.

### Đoạn mã

```cpp
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
```

### Giải thích
- Đầu tiên, ta duyệt qua tất cả các phần tử trong mảng bằng cách sử dụng hai vòng lặp.
- Với mỗi cặp phần tử, ta kiểm tra nếu tổng của chúng bằng `target`. Nếu có, trả về chỉ số của hai phần tử đó.
- Nếu không tìm thấy cặp nào, trả về mảng rỗng.

## Cách 2: Dùng HashMap (Bảng Băm)

### Mô tả

Phương pháp này sử dụng một bảng băm (hash map) để lưu trữ các giá trị đã gặp và chỉ số của chúng. Mỗi lần gặp một phần tử mới, ta tính giá trị cần tìm (target - phần tử hiện tại) và kiểm tra xem giá trị đó đã có trong bảng băm chưa.

### Phức tạp thời gian và không gian
- **Phức tạp thời gian**: O(n), vì ta chỉ cần duyệt qua mảng một lần.
- **Phức tạp không gian**: O(n), vì ta sử dụng một bảng băm để lưu trữ các phần tử.

### Đoạn mã

```cpp
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m; // Bảng băm lưu trữ các phần tử đã gặp
        for (int i = 0; i < nums.size(); i++)
        {
            int val = target - nums[i]; // Tính giá trị cần tìm để tổng bằng target
            if (m.count(val)) // Nếu giá trị cần tìm đã có trong bảng băm
            {
                return {i, m[val]}; // Trả về chỉ số của phần tử hiện tại và phần tử đã gặp
            }
            m[nums[i]] = i; // Lưu phần tử hiện tại vào bảng băm
        }
        return {};
    }
};
```

### Giải thích
- Đầu tiên, ta tạo một bảng băm `m` để lưu trữ các phần tử đã gặp và chỉ số của chúng.
- Với mỗi phần tử trong mảng, ta tính giá trị `val = target - nums[i]`. Nếu `val` đã tồn tại trong bảng băm, điều này có nghĩa là ta đã tìm thấy một cặp phần tử có tổng bằng `target`. Ta trả về chỉ số của phần tử hiện tại và chỉ số của phần tử đã gặp trước đó.
- Nếu không tìm thấy cặp nào, ta thêm phần tử hiện tại vào bảng băm để kiểm tra với các phần tử sau.

## Tổng kết

- **Cách 1** đơn giản nhưng kém hiệu quả vì phải duyệt qua tất cả các cặp phần tử trong mảng (O(n^2)).
- **Cách 2** tối ưu hơn nhiều nhờ việc sử dụng bảng băm để giảm phức tạp thời gian xuống O(n). Đây là phương pháp được ưa chuộng hơn trong các bài toán này.

Cả hai cách đều trả về chỉ số của hai phần tử trong mảng sao cho tổng của chúng bằng `target`. Chọn cách giải phù hợp tùy thuộc vào yêu cầu về hiệu suất và độ phức tạp của bài toán.
