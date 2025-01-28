class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]  # nums là một danh sách các số nguyên.
        :rtype: int            # Hàm trả về giá trị lớn nhất của tổng dãy con liên tiếp.
        """
        total = 0             # Biến tổng tạm thời, dùng để tính tổng của dãy con hiện tại.
        result = nums[0]      # Khởi tạo kết quả là phần tử đầu tiên của danh sách.

        # Duyệt qua từng phần tử trong danh sách.
        for number in nums:
            # Nếu tổng tạm thời < 0, đặt lại tổng tạm thời về 0.
            if total < 0: 
                total = 0
            
            # Cộng giá trị hiện tại vào tổng tạm thời.
            total += number
            
            # Cập nhật kết quả nếu tổng tạm thời lớn hơn kết quả hiện tại.
            result = max(result, total)
        
        # Trả về kết quả lớn nhất.
        return result
