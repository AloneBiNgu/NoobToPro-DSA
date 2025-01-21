class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.length();
        if (n < 2 || n % 2 != 0)
            return false; // Nếu chuỗi quá ngắn hoặc có độ dài lẻ, trả về false.

        int ans = 0;    // Đếm số cặp ngoặc hợp lệ.
        stack<char> st; // Sử dụng ngăn xếp (stack) để lưu các dấu ngoặc mở.

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]); // Đẩy dấu ngoặc mở vào ngăn xếp.
            }

            if (st.size() < 1)
                continue; // Nếu ngăn xếp trống, bỏ qua.

            if (s[i] == ')')
            {
                char c = st.top();
                if (c != '(')
                    return false; // Nếu dấu ngoặc không khớp, trả về false.
                st.pop();         // Xóa dấu ngoặc mở tương ứng khỏi ngăn xếp.
                ans++;
            }
            if (s[i] == ']')
            {
                char c = st.top();
                if (c != '[')
                    return false;
                st.pop();
                ans++;
            }
            if (s[i] == '}')
            {
                char c = st.top();
                if (c != '{')
                    return false;
                st.pop();
                ans++;
            }
        }

        cout << ans;         // In số cặp ngoặc hợp lệ (chỉ để debug).
        return ans == n / 2; // Kiểm tra nếu số cặp ngoặc hợp lệ bằng một nửa độ dài chuỗi.
    }
};