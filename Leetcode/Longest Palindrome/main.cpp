class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> hashSet; // Bảng băm để đếm tần suất ký tự
        int res = 0;                      // Biến lưu độ dài palindrome lớn nhất tìm được

        // Duyệt qua từng ký tự trong chuỗi để đếm số lần xuất hiện
        for (char ch : s)
        {
            hashSet[ch] += 1;
            // Nếu số lần xuất hiện của ký tự hiện tại là chẵn, cộng vào kết quả
            if (hashSet[ch] % 2 == 0)
                res += 2;
        }

        // Kiểm tra xem có ký tự nào xuất hiện lẻ lần không
        for (char ch : s)
        {
            if (hashSet[ch] % 2)
            {
                res += 1; // Có thể lấy một ký tự lẻ làm trung tâm palindrome
                break;    // Chỉ cần một ký tự lẻ duy nhất
            }
        }

        return res; // Trả về độ dài palindrome lớn nhất
    }
};