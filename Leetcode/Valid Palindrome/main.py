class Solution:
    # Hàm chuyển ký tự thành chữ thường và kiểm tra tính hợp lệ
    def convert_to_lowercase(self, c):
        ascii_code = ord(c)  # Lấy mã ASCII của ký tự

        # Loại bỏ ký tự khoảng trắng
        if ascii_code == 32:
            return False

        # Chuyển ký tự in hoa thành chữ thường
        if 65 <= ascii_code <= 90:
            c = chr(ascii_code + 32)
            return True

        # Giữ nguyên ký tự số
        if 48 <= ascii_code <= 57:
            return True

        # Loại bỏ các ký tự không hợp lệ
        if ascii_code < 97 or ascii_code > 122:
            return False
        else:
            return True

    # Hàm kiểm tra chuỗi có phải là palindrome hay không
    def is_palindrome(self, s):
        # Loại bỏ các ký tự không hợp lệ bằng cách sử dụng convert_to_lowercase
        while True:
            flag = True
            i = 0
            while i < len(s):
                if not self.convert_to_lowercase(s[i]):
                    flag = False
                    s = s[:i] + s[i + 1:]  # Xóa ký tự không hợp lệ
                else:
                    i += 1
            if flag:
                break

        # Kiểm tra tính đối xứng của chuỗi
        for i in range(len(s)):
            if s[i] != s[len(s) - 1 - i]:
                return False

        return True
