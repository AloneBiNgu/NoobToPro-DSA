# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # Hàm duyệt sâu đệ quy để đảo ngược cây
    def dfs(self, root):
        # Hoán đổi con trái và con phải
        root.left, root.right = root.right, root.left

        # Đệ quy đảo ngược cây con trái
        if root.left is not None:
            self.dfs(root.left)

        # Đệ quy đảo ngược cây con phải
        if root.right is not None:
            self.dfs(root.right)
    
    # Hàm chính để khởi động việc đảo ngược cây
    def invertTree(self, root):
        # Nếu cây rỗng thì trả về None
        if root is None:
            return None

        # Gọi hàm dfs để thực hiện đảo ngược
        self.dfs(root)
        return root
