# Cách 1
class Solution:
    def maxProfit(self, prices):
        n = len(prices)
        if n == 0:
            return 0

        # Khởi tạo hai danh sách minPrices và maxPrices
        minPrices = [float('inf')] * n
        maxPrices = [0] * n

        # Tính giá trị nhỏ nhất từ trái sang phải
        for i in range(n):
            minPrices[i] = prices[i] if i == 0 else min(minPrices[i - 1], prices[i])

        # Tính giá trị lớn nhất từ phải sang trái
        for i in range(n - 1, -1, -1):
            maxPrices[i] = prices[i] if i == n - 1 else max(maxPrices[i + 1], prices[i])

        # Tính lợi nhuận tối đa
        maxProfit = 0
        for i in range(n):
            maxProfit = max(maxProfit, maxPrices[i] - minPrices[i])

        return maxProfit

# Cách 2
class Solution:
    def maxProfit(self, prices):
        if not prices:
            return 0

        buyPrice = prices[0]  # Giá mua nhỏ nhất
        profit = 0  # Lợi nhuận tối đa ban đầu

        # Duyệt qua từng giá
        for price in prices[1:]:
            if price < buyPrice:
                # Cập nhật giá mua nhỏ nhất
                buyPrice = price
            elif price - buyPrice > profit:
                # Cập nhật lợi nhuận tối đa
                profit = price - buyPrice

        return profit
