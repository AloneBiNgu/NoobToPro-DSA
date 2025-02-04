// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1, right = n; // Giới hạn tìm kiếm từ phiên bản 1 đến phiên bản n
        int badVersion = n;      // Giả sử phiên bản xấu nhất là phiên bản cuối cùng

        while (left < right)
        {
            long long mid = ((long long)right + (long long)left - 1) / 2;
            // Tìm phiên bản ở giữa bằng cách lấy trung bình cộng để tránh tràn số

            if (isBadVersion(mid))
            {                                           // Nếu mid là phiên bản lỗi
                badVersion = min(badVersion, (int)mid); // Cập nhật badVersion với giá trị nhỏ nhất
                right = mid;                            // Tiếp tục tìm kiếm về bên trái
            }
            else
            {
                left = mid + 1; // Nếu mid không phải là phiên bản lỗi, tìm kiếm về bên phải
            }
        }

        return badVersion; // Trả về phiên bản lỗi đầu tiên tìm được
    }
};