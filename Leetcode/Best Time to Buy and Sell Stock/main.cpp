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
            minPrices[i] = i == 0 ? prices[i] : min(minPrices[i - 1], prices[i]);
        }

        // Tính giá trị lớn nhất cho từng ngày từ phải sang trái
        for (int i = n - 1; i >= 0; i--)
        {
            maxPrices[i] = i == n - 1 ? prices[i] : max(maxPrices[i + 1], prices[i]);
        }

        // Tính lợi nhuận tối đa
        int maxProfit = 0;
        for (int i = 0; i < n; i++)
        {
            maxProfit = max(maxProfit, maxPrices[i] - minPrices[i]);
        }

        return maxProfit;
    }
};