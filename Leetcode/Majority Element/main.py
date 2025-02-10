class Solution:
    def majorityElement(self, nums):
        # Kích thước của mảng
        n = len(nums)
        # Số lần tối thiểu để một phần tử có thể chiếm đa số
        minAppear = n // 2
        # Khởi tạo hai chỉ số: left ở đầu mảng, right ở cuối mảng
        left, right = 0, n - 1
        
        # Khởi tạo flag để theo dõi số lần xuất hiện lớn nhất và kết quả
        flag = float('-inf')
        result = nums[0]
        
        # Tạo một dictionary để đếm số lần xuất hiện của mỗi phần tử
        m = {}
        
        # Đếm số lần xuất hiện của phần tử ở giữa mảng
        m[nums[(right + left) // 2]] = m.get(nums[(right + left) // 2], 0) + 1
        
        # Duyệt qua mảng từ hai đầu
        while left < right:
            # Đếm số lần xuất hiện của phần tử ở vị trí left và right
            m[nums[left]] = m.get(nums[left], 0) + 1
            m[nums[right]] = m.get(nums[right], 0) + 1

            # Kiểm tra nếu số lần xuất hiện của phần tử tại left lớn hơn minAppear
            # và nó xuất hiện nhiều nhất, cập nhật kết quả
            if m[nums[left]] > minAppear and m[nums[left]] > flag:
                result = nums[left]
                flag = m[nums[left]]

            # Kiểm tra nếu số lần xuất hiện của phần tử tại right lớn hơn minAppear
            # và nó xuất hiện nhiều nhất, cập nhật kết quả
            if m[nums[right]] > minAppear and m[nums[right]] > flag:
                result = nums[right]
                flag = m[nums[right]]
            
            # Di chuyển con trỏ về phía nhau
            left += 1
            right -= 1
        
        # In ra các phần tử và số lần xuất hiện của chúng
        for key, value in m.items():
            print(key, value)
        
        # Trả về kết quả
        return result
