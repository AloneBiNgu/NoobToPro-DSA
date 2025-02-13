class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        level = [0]  # Use a list to hold the level variable
        def dfs(root):
            if not root:
                return 0
            left = dfs(root.left)
            right = dfs(root.right)
            level[0] = max(level[0], left + right)  # Modify the list element
            return max(left, right) + 1
        dfs(root)
        return level[0]  # Return the first element of the list
