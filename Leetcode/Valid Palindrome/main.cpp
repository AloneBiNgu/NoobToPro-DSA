// Cách 1: Sử dụng convertToLowercase để loại bỏ ký tự không hợp lệ
// Phức tạp thời gian: O(n^2), Phức tạp không gian: O(1)

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

// Cách 2: Sử dụng isNormalCharacter và toLowercase để kiểm tra và chuyển ký tự
// Phức tạp thời gian: O(n), Phức tạp không gian: O(n)
class Solution
{
public:
    // Hàm kiểm tra nếu ký tự là ký tự hợp lệ (chữ cái hoặc số)
    bool isNormalCharacter(char c)
    {
        if ((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))
            return true; // Ký tự hợp lệ (chữ cái hoặc số)
        return false;    // Ký tự không hợp lệ
    }

    // Hàm chuyển ký tự in hoa thành chữ thường
    char toLowercase(char c)
    {
        if (c >= 'A' && c <= 'Z')
            return (char)(c - 'A' + 'a'); // Chuyển thành chữ thường
        return c;                         // Nếu không phải ký tự in hoa, trả về nguyên vẹn
    }

    // Hàm kiểm tra chuỗi có phải là palindrome hay không
    bool isPalindrome(string s)
    {
        string temp; // Tạo một chuỗi tạm để lưu các ký tự hợp lệ đã chuyển sang chữ thường
        for (int i = 0; i < s.length(); i++)
        {
            if (isNormalCharacter(s[i])) // Nếu ký tự hợp lệ
            {
                temp.push_back(toLowercase(s[i])); // Thêm ký tự vào chuỗi tạm sau khi chuyển thành chữ thường
            }
        }

        // Kiểm tra tính đối xứng của chuỗi temp
        int pointerOne = 0, pointerTwo = temp.length() - 1;
        while (pointerOne < pointerTwo)
        {
            if (temp[pointerOne] != temp[pointerTwo]) // Nếu hai ký tự không bằng nhau
            {
                return false; // Không phải palindrome
            }

            pointerOne += 1; // Di chuyển pointerOne về phía trung tâm
            pointerTwo -= 1; // Di chuyển pointerTwo về phía trung tâm
        }

        return true; // Nếu không có sự khác biệt, chuỗi là palindrome
    }
};