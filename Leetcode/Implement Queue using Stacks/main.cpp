// Cách 1: Sử dụng unordered_map thay cho 2 stack (tối ưu nhất)
class MyQueue
{
private:
    unordered_map<int, int> st; // Dùng unordered_map để lưu trữ các phần tử trong hàng đợi.

public:
    // Hàm khởi tạo MyQueue
    MyQueue()
    {
    }

    // Hàm thêm phần tử vào hàng đợi
    void push(int x)
    {
        st[st.size()] = x; // Thêm phần tử `x` vào cuối hàng đợi, với chỉ số là kích thước hiện tại của unordered_map.
        cout << "Push command:\n";

        // In ra trạng thái hiện tại của hàng đợi
        for (int i = 0; i < st.size(); i++)
        {
            cout << st[i] << " ";
        }
        cout << "\n";
    }

    // Hàm xóa phần tử khỏi đầu hàng đợi và trả về phần tử đó
    int pop()
    {
        cout << "Pop command:\n";
        int result = st[0]; // Lấy phần tử ở vị trí đầu tiên
        // Di chuyển tất cả các phần tử phía sau lên một vị trí phía trước
        for (int i = 0; i < st.size() - 1; i++)
        {
            st[i] = st[i + 1];
        }
        st.erase(st.size() - 1); // Xóa phần tử cuối cùng (vì nó đã bị di chuyển)

        // In ra trạng thái hiện tại của hàng đợi
        for (int i = 0; i < st.size(); i++)
        {
            cout << st[i] << " ";
        }
        cout << "\n";
        return result; // Trả về phần tử đã bị loại bỏ
    }

    // Hàm xem phần tử đầu tiên trong hàng đợi mà không xóa nó
    int peek()
    {
        return st[0]; // Trả về phần tử đầu tiên trong hàng đợi
    }

    // Hàm kiểm tra xem hàng đợi có rỗng không
    bool empty()
    {
        return (st.size() == 0); // Nếu kích thước hàng đợi bằng 0 thì trả về true, nghĩa là hàng đợi rỗng
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */