class Solution
{
public:
    string addBinary(string a, string b)
    {
        // Khởi tạo chỉ số cho hai chuỗi a và b, bắt đầu từ vị trí cuối cùng của mỗi chuỗi
        int i = a.length() - 1, j = b.length() - 1;

        // Khởi tạo biến carry để lưu trữ giá trị mang, bắt đầu từ 0
        int carry = 0;

        // Khởi tạo chuỗi result để lưu trữ kết quả cuối cùng
        string result;

        // Lặp cho đến khi cả hai chuỗi được duyệt hết hoặc còn mang (carry)
        while (i >= 0 || j >= 0 || carry == 1)
        {
            // Nếu còn bit ở chuỗi a, cộng giá trị tại vị trí i vào carry
            if (i >= 0)
            {
                carry += a[i] - '0'; // '0' được trừ để chuyển ký tự thành số
                i--;                 // Di chuyển chỉ số i sang trái
            }

            // Nếu còn bit ở chuỗi b, cộng giá trị tại vị trí j vào carry
            if (j >= 0)
            {
                carry += b[j] - '0'; // '0' được trừ để chuyển ký tự thành số
                j--;                 // Di chuyển chỉ số j sang trái
            }

            // Thêm kết quả của phép cộng vào chuỗi result
            // carry % 2 cho ra kết quả tại vị trí hiện tại (0 hoặc 1)
            result += (carry % 2) + '0'; // Chuyển từ số sang ký tự

            // Cập nhật carry cho vòng lặp tiếp theo
            carry /= 2; // Chia mang cho 2 để đưa carry sang vị trí kế tiếp
        }

        // Đảo ngược chuỗi kết quả để có thứ tự đúng
        reverse(result.begin(), result.end());

        // Trả về kết quả cuối cùng
        return result;
    }
};
