# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    # Hàm chèn một nút mới có giá trị `val` vào cuối danh sách liên kết
    def insert(self, head, val):
        # Tạo một nút mới với giá trị `val`
        new_node = ListNode(val)

        # Nếu danh sách hiện tại rỗng (hoặc head có giá trị mặc định là 0), gán nút mới làm head
        if head.val == 0 and head.next is None:
            head.val = val
            return

        # Tìm nút cuối cùng trong danh sách liên kết
        last = head
        while last.next is not None:
            last = last.next

        # Gắn nút mới vào cuối danh sách
        last.next = new_node

    # Hàm trộn hai danh sách liên kết đã được sắp xếp
    def mergeTwoLists(self, list1, list2):
        temp_array = []  # Mảng tạm thời để lưu trữ các giá trị từ cả hai danh sách
        result = ListNode()  # Danh sách liên kết kết quả

        # Duyệt qua danh sách liên kết `list1` và thêm các giá trị vào mảng tạm thời
        temp = list1
        while temp is not None:
            temp_array.append(temp.val)
            temp = temp.next

        # Duyệt qua danh sách liên kết `list2` và thêm các giá trị vào mảng tạm thời
        temp = list2
        while temp is not None:
            temp_array.append(temp.val)
            temp = temp.next

        # Nếu không có giá trị nào trong cả hai danh sách, trả về danh sách rỗng
        if not temp_array:
            return None

        # Sắp xếp các giá trị trong mảng theo thứ tự tăng dần
        temp_array.sort()

        # Tạo lại danh sách liên kết từ mảng đã được sắp xếp
        for val in temp_array:
            self.insert(result, val)

        return result  # Trả về danh sách liên kết đã được trộn và sắp xếp