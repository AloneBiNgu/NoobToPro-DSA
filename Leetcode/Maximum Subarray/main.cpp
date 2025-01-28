class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // Nếu mảng chỉ có một phần tử, trả về chính phần tử đó
        if (nums.size() == 1)
            return nums[0];

        int total = 0;        // Tổng hiện tại của dãy con
        int result = nums[0]; // Tổng lớn nhất tìm được

        // Duyệt qua từng phần tử trong mảng
        for (int i = 0; i < nums.size(); i++)
        {
            // Nếu tổng hiện tại < 0, đặt lại tổng về 0
            if (total < 0)
            {
                total = 0;
            }

            // Cộng phần tử hiện tại vào tổng
            total += nums[i];

            // Cập nhật kết quả nếu tổng hiện tại lớn hơn tổng lớn nhất
            result = max(result, total);
        }

        return result; // Trả về tổng lớn nhất
    }
};