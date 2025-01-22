class Solution:
    def maxProfit(self, prices):
        n = len(prices)
        
        # Khởi tạo hai danh sách để lưu giá trị nhỏ nhất và lớn nhất theo từng ngày
        minPrices = [float('inf')] * n  # Giá trị nhỏ nhất khởi tạo với dương vô cực
        maxPrices = [0] * n            # Giá trị lớn nhất khởi tạo với 0

        # Tính giá trị nhỏ nhất cho từng ngày từ trái sang phải
        for i in range(n):
            minPrices[i] = prices[i] if i == 0 else min(minPrices[i - 1], prices[i])
        
        # Tính giá trị lớn nhất cho từng ngày từ phải sang trái
        for i in range(n - 1, -1, -1):
            maxPrices[i] = prices[i] if i == n - 1 else max(maxPrices[i + 1], prices[i])

        # Tính lợi nhuận tối đa
        maxProfit = 0
        for i in range(n):
            maxProfit = max(maxProfit, maxPrices[i] - minPrices[i])
        
        return maxProfit
