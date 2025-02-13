class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        hashMap = dict()
        for num in nums:
            hashMap[num] = hashMap.get(num, 0) + 1
            if hashMap[num] > 1:
                return True
        return False