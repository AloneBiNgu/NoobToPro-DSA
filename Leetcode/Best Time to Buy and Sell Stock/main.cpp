// Cách 1
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        // Khởi tạo hai vector để lưu giá trị nhỏ nhất và lớn nhất theo từng ngày
        vector<int> minPrices(n, INT_MAX), maxPrices(n, 0);

        // Tính giá trị nhỏ nhất cho từng ngày từ trái sang phải
        for (int i = 0; i < n; i++)
        {
            // Ngày đầu tiên chỉ có thể là giá mua
            // Ngày tiếp theo, so sánh giá trị nhỏ nhất trước đó và giá hiện tại
            minPrices[i] = i == 0 ? prices[i] : min(minPrices[i - 1], prices[i]);
        }

        // Tính giá trị lớn nhất cho từng ngày từ phải sang trái
        for (int i = n - 1; i >= 0; i--)
        {
            // Ngày cuối cùng chỉ có thể là giá bán
            // Ngày trước đó, so sánh giá trị lớn nhất sau đó và giá hiện tại
            maxPrices[i] = i == n - 1 ? prices[i] : max(maxPrices[i + 1], prices[i]);
        }

        // Tính lợi nhuận tối đa bằng cách duyệt qua tất cả các ngày
        int maxProfit = 0;
        for (int i = 0; i < n; i++)
        {
            // Lợi nhuận tại ngày i = giá bán cao nhất - giá mua thấp nhất
            maxProfit = max(maxProfit, maxPrices[i] - minPrices[i]);
        }

        return maxProfit;
    }
};

// Cách 2
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buyPrice = prices[0]; // Giá mua nhỏ nhất tại thời điểm ban đầu
        int profit = 0;           // Lợi nhuận tối đa ban đầu

        // Duyệt qua từng ngày
        for (int i = 1; i < prices.size(); i++)
        {
            if (buyPrice > prices[i])
            {
                // Nếu giá hiện tại thấp hơn giá mua, cập nhật giá mua nhỏ nhất
                buyPrice = prices[i];
            }
            else if (prices[i] - buyPrice > profit)
            {
                // Nếu lợi nhuận hiện tại lớn hơn lợi nhuận cũ, cập nhật lợi nhuận
                profit = prices[i] - buyPrice;
            }
        }

        return profit; // Trả về lợi nhuận tối đa
    }
};
