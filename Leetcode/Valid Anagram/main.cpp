class Solution
{
public:
    // Hàm kiểm tra xem hai chuỗi có phải là anagram của nhau hay không
    bool isAnagram(string s, string t)
    {
        // Nếu độ dài hai chuỗi khác nhau, chắc chắn không phải anagram
        if (s.length() != t.length())
            return false;

        // Sử dụng hai bản đồ (map) để đếm số lần xuất hiện của các ký tự trong hai chuỗi
        map<int, int> m1, m2;

        // Duyệt qua từng ký tự trong chuỗi s và tăng giá trị tương ứng trong map m1
        for (char c : s)
        {
            m1[(int)c] += 1; // (int)c chuyển ký tự sang mã ASCII để làm key
        }

        // Duyệt qua từng ký tự trong chuỗi t và tăng giá trị tương ứng trong map m2
        for (char c : t)
        {
            m2[(int)c] += 1; // Tương tự như trên
        }

        // Kiểm tra từng ký tự trong chuỗi t
        for (char c : t)
        {
            // Nếu số lần xuất hiện của ký tự trong m1 khác m2, không phải anagram
            if (m1[(int)c] != m2[(int)c])
                return false;
        }

        // Nếu tất cả các kiểm tra đều đạt, hai chuỗi là anagram
        return true;
    }
};

class Solution
{
public:
    // Hàm kiểm tra xem hai chuỗi có phải là anagram của nhau hay không
    bool isAnagram(string s, string t)
    {
        // Nếu độ dài hai chuỗi khác nhau, chắc chắn không phải anagram
        if (s.length() != t.length())
            return false;

        // Sử dụng `unordered_map` để đếm số lần xuất hiện của các ký tự
        unordered_map<int, int> m;

        // Duyệt qua từng ký tự trong chuỗi `s`, tăng số lần xuất hiện trong map
        for (char c : s)
        {
            m[c]++;
        }

        // Duyệt qua từng ký tự trong chuỗi `t`, giảm số lần xuất hiện trong map
        for (char c : t)
        {
            m[c]--;
        }

        // Kiểm tra giá trị trong map:
        // Nếu bất kỳ giá trị nào không bằng 0, hai chuỗi không phải là anagram
        for (auto it : m)
        {
            if (it.second != 0)
                return false;
        }

        // Nếu tất cả các kiểm tra đều đạt, hai chuỗi là anagram
        return true;
    }
};
