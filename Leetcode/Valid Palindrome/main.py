# Cách 1: Sử dụng convertToLowercase để loại bỏ ký tự không hợp lệ
# Phức tạp thời gian: O(n^2), Phức tạp không gian: O(1)
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

# Cách 2: Sử dụng isNormalCharacter và toLowercase để kiểm tra và chuyển ký tự
# Phức tạp thời gian: O(n), Phức tạp không gian: O(n)
class Solution:
    # Hàm kiểm tra nếu ký tự là ký tự hợp lệ (chữ cái hoặc số)
    def isNormalCharacter(self, c: str) -> bool:
        if ('A' <= c <= 'Z') or ('0' <= c <= '9') or ('a' <= c <= 'z'):
            return True  # Ký tự hợp lệ (chữ cái hoặc số)
        return False  # Ký tự không hợp lệ

    # Hàm chuyển ký tự in hoa thành chữ thường
    def toLowercase(self, c: str) -> str:
        if 'A' <= c <= 'Z':
            return chr(ord(c) - ord('A') + ord('a'))  # Chuyển thành chữ thường
        return c  # Nếu không phải ký tự in hoa, trả về nguyên vẹn

    # Hàm kiểm tra chuỗi có phải là palindrome hay không
    def isPalindrome(self, s: str) -> bool:
        temp = []  # Tạo một chuỗi tạm để lưu các ký tự hợp lệ đã chuyển sang chữ thường
        for char in s:
            if self.isNormalCharacter(char):  # Nếu ký tự hợp lệ
                temp.append(self.toLowercase(char))  # Thêm ký tự vào chuỗi tạm sau khi chuyển thành chữ thường

        # Kiểm tra tính đối xứng của chuỗi temp
        pointer_one = 0
        pointer_two = len(temp) - 1
        while pointer_one < pointer_two:
            if temp[pointer_one] != temp[pointer_two]:  # Nếu hai ký tự không bằng nhau
                return False  # Không phải palindrome
            pointer_one += 1  # Di chuyển pointer_one về phía trung tâm
            pointer_two -= 1  # Di chuyển pointer_two về phía trung tâm

        return True  # Nếu không có sự khác biệt, chuỗi là palindrome
