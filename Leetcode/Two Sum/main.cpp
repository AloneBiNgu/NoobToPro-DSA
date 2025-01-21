// Cách 1: Sử dụng hai vòng lặp (brute force)
// Phức tạp thời gian: O(n^2), Phức tạp không gian: O(1)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // Duyệt qua tất cả cặp số trong mảng để tìm tổng bằng target
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                // Nếu tổng của hai số bằng target, trả về chỉ số của chúng
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }

        // Nếu không tìm thấy cặp nào, trả về mảng rỗng
        return {};
    }
};

// Cách 2: Sử dụng bảng băm (HashMap) để tối ưu
// Phức tạp thời gian: O(n), Phức tạp không gian: O(n)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m; // Sử dụng bảng băm để lưu trữ giá trị và chỉ số của các phần tử đã gặp
        for (int i = 0; i < nums.size(); i++)
        {
            int val = target - nums[i]; // Tính giá trị cần tìm để tổng bằng target
            if (m.count(val))           // Nếu giá trị đó đã có trong bảng băm
            {
                return {i, m[val]}; // Trả về chỉ số của phần tử hiện tại và phần tử đã gặp
            }

            m[nums[i]] = i; // Thêm phần tử hiện tại vào bảng băm
        }

        // Nếu không tìm thấy cặp nào, trả về mảng rỗng
        return {};
    }
};