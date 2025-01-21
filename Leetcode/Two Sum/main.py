# Cách 1: Sử dụng hai vòng lặp (brute force)
# Phức tạp thời gian: O(n^2), Phức tạp không gian: O(1)
class Solution:
    def twoSum(self, nums, target):
        # Duyệt qua tất cả cặp số trong mảng để tìm tổng bằng target
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                # Nếu tổng của hai số bằng target, trả về chỉ số của chúng
                if nums[i] + nums[j] == target:
                    return [i, j]
        # Nếu không tìm thấy cặp nào, trả về danh sách rỗng
        return []

# Cách 2: Sử dụng bảng băm (HashMap) để tối ưu
# Phức tạp thời gian: O(n), Phức tạp không gian: O(n)
class Solution:
    def twoSum(self, nums, target):
        hash_map = {}  # Sử dụng bảng băm để lưu trữ giá trị và chỉ số
        for i, num in enumerate(nums):
            val = target - num  # Tính giá trị cần tìm
            if val in hash_map:  # Nếu giá trị đó đã tồn tại trong bảng băm
                return [i, hash_map[val]]  # Trả về chỉ số hiện tại và chỉ số đã gặp
            hash_map[num] = i  # Lưu giá trị hiện tại và chỉ số vào bảng băm
        # Nếu không tìm thấy cặp nào, trả về danh sách rỗng
        return []
