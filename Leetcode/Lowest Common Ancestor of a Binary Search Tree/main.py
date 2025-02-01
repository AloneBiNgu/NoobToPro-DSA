# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        """
        Hàm tìm tổ tiên chung gần nhất (LCA) của hai nút p và q trong cây nhị phân.
        
        :param root: Gốc của cây nhị phân.
        :param p: Nút đầu tiên cần tìm LCA.
        :param q: Nút thứ hai cần tìm LCA.
        :return: Con trỏ tới nút LCA hoặc None nếu không tìm thấy.
        """
        # Nếu root là None, không có gì để tìm kiếm
        if root is None:
            return None

        # Nếu root chính là một trong hai nút p hoặc q, trả về root vì nó có thể là LCA
        if root == p or root == q:
            return root

        # Tìm kiếm trong cây con bên trái
        left = self.lowestCommonAncestor(root.left, p, q)

        # Tìm kiếm trong cây con bên phải
        right = self.lowestCommonAncestor(root.right, p, q)

        # Nếu tìm thấy p và q ở cả hai nhánh trái & phải, root chính là LCA
        if left is not None and right is not None:
            return root

        # Nếu chỉ tìm thấy ở một phía, trả về phía đó (nút p hoặc q hoặc LCA đã tìm thấy trước đó)
        return left if left is not None else right
