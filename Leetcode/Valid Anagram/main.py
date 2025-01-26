class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Nếu độ dài hai chuỗi khác nhau, chắc chắn không phải anagram
        if len(s) != len(t):
            return False

        # Sử dụng hai từ điển để đếm số lần xuất hiện của các ký tự trong hai chuỗi
        m1 = {}
        m2 = {}

        # Duyệt qua từng ký tự trong chuỗi s và tăng giá trị tương ứng trong từ điển m1
        for c in s:
            m1[c] = m1.get(c, 0) + 1

        # Duyệt qua từng ký tự trong chuỗi t và tăng giá trị tương ứng trong từ điển m2
        for c in t:
            m2[c] = m2.get(c, 0) + 1

        # Kiểm tra từng ký tự trong chuỗi t
        for c in t:
            # Nếu số lần xuất hiện của ký tự trong m1 khác m2, không phải anagram
            if m1.get(c, 0) != m2.get(c, 0):
                return False

        # Nếu tất cả các kiểm tra đều đạt, hai chuỗi là anagram
        return True

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Nếu độ dài hai chuỗi khác nhau, chắc chắn không phải anagram
        if len(s) != len(t):
            return False

        # Sử dụng dictionary để đếm số lần xuất hiện của các ký tự
        m = {}

        # Duyệt qua từng ký tự trong chuỗi `s`, tăng số lần xuất hiện trong dictionary
        for c in s:
            m[c] = m.get(c, 0) + 1

        # Duyệt qua từng ký tự trong chuỗi `t`, giảm số lần xuất hiện trong dictionary
        for c in t:
            if c in m:
                m[c] -= 1
            else:
                return False

        # Kiểm tra giá trị trong dictionary:
        # Nếu bất kỳ giá trị nào không bằng 0, hai chuỗi không phải là anagram
        for count in m.values():
            if count != 0:
                return False

        # Nếu tất cả các kiểm tra đều đạt, hai chuỗi là anagram
        return True
