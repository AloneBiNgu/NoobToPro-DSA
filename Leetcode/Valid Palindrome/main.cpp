class Solution
{
public:
    // Hàm chuyển ký tự thành chữ thường và kiểm tra tính hợp lệ
    bool convertToLowercase(char &c)
    {
        int asciiCode = (int)c; // Lấy mã ASCII của ký tự

        // Loại bỏ ký tự khoảng trắng
        if (asciiCode == 32)
            return false;

        // Chuyển ký tự in hoa thành chữ thường
        if (asciiCode >= 65 && asciiCode <= 90)
        {
            c = (char)(asciiCode + 32);
            return true;
        }

        // Giữ nguyên ký tự số
        if (asciiCode >= 48 && asciiCode <= 57)
            return true;

        // Loại bỏ các ký tự không hợp lệ
        if (asciiCode < 97 || asciiCode > 122)
        {
            return false;
        }
        else
        {
            return true;
        }

        return false;
    }

    // Hàm kiểm tra chuỗi có phải là palindrome hay không
    bool isPalindrome(string s)
    {
        // Loại bỏ các ký tự không hợp lệ bằng cách sử dụng convertToLowercase
        while (true)
        {
            bool flag = true;
            for (int i = 0; i < s.size(); i++)
            {
                if (convertToLowercase(s[i]) == false)
                {
                    flag = false;
                    s.erase(s.begin() + i); // Xóa ký tự không hợp lệ
                }
            }
            if (flag == true)
                break; // Thoát vòng lặp khi chuỗi chỉ còn ký tự hợp lệ
        }

        // Kiểm tra tính đối xứng của chuỗi
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != s[s.size() - (1 + i)])
                return false;
        }

        return true;
    }
};