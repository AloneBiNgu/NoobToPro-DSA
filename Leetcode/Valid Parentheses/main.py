class Solution:
    def isValid(self, s: str) -> bool:
        n = len(s)
        if n < 2 or n % 2 != 0:
            return False  # Nếu chuỗi quá ngắn hoặc có độ dài lẻ, trả về False.

        stack = []  # Sử dụng danh sách như một ngăn xếp để lưu các dấu ngoặc mở.

        # Duyệt qua từng ký tự trong chuỗi
        for char in s:
            if char in "([{":  # Nếu là dấu ngoặc mở, thêm vào ngăn xếp.
                stack.append(char)
            elif not stack:  # Nếu ngăn xếp trống nhưng gặp dấu ngoặc đóng, chuỗi không hợp lệ.
                return False
            else:
                # Kiểm tra xem dấu ngoặc mở trên đỉnh ngăn xếp có khớp không.
                top = stack[-1]
                stack.pop()
                if char == ')' and top != '(':
                    return False
                if char == ']' and top != '[':
                    return False
                if char == '}' and top != '{':
                    return False

        # Sau khi duyệt xong, nếu ngăn xếp vẫn còn phần tử thì chuỗi không hợp lệ.
        return len(stack) == 0
