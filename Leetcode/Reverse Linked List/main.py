# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def reverseList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        node = None  # Biến lưu trữ danh sách liên kết mới sau khi đảo ngược

        # Duyệt qua từng phần tử trong danh sách
        while head:
            temp = head.next  # Lưu lại node tiếp theo để không bị mất liên kết
            head.next = node  # Đảo chiều liên kết: trỏ node hiện tại về node trước đó
            node = head  # Cập nhật node mới đã đảo ngược
            head = temp  # Di chuyển con trỏ head tới node tiếp theo
        
        return node  # Trả về node đầu tiên của danh sách đã đảo ngược
