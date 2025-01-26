class Solution:
    def search(self, nums, target):
        left, right = 0, len(nums)
        while left < right:
            mid = (right + left) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                left += 1
            else:
                right -= 1
        return -1

class Solution:
    def search(self, nums, target):
        left, right = 0, len(nums)
        while left < right:
            mid = (right + left) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        return -1
