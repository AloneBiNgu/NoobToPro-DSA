/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    // Hàm chèn một nút mới có giá trị `val` vào cuối danh sách liên kết
    void insert(ListNode *&head, int val)
    {
        // Tạo một nút mới với giá trị `val`
        ListNode *newNode = new ListNode();
        newNode->val = val;
        newNode->next = nullptr;

        // Nếu danh sách hiện tại rỗng (hoặc head có giá trị mặc định là 0), gán nút mới làm head
        if (head->val == 0)
        {
            head = newNode;
            return;
        }

        // Tìm nút cuối cùng trong danh sách liên kết
        ListNode *last = head;
        while (last->next != nullptr)
        {
            last = last->next;
        }

        // Gắn nút mới vào cuối danh sách
        last->next = newNode;
    };

    // Hàm trộn hai danh sách liên kết đã được sắp xếp
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        vector<int> tempArray;             // Mảng tạm thời để lưu trữ các giá trị từ cả hai danh sách
        ListNode *result = new ListNode(); // Danh sách liên kết kết quả

        // Duyệt qua danh sách liên kết `list1` và thêm các giá trị vào mảng tạm thời
        ListNode *temp = list1;
        while (temp != nullptr)
        {
            tempArray.push_back(temp->val);
            temp = temp->next;
        }

        // Duyệt qua danh sách liên kết `list2` và thêm các giá trị vào mảng tạm thời
        temp = list2;
        while (temp != nullptr)
        {
            tempArray.push_back(temp->val);
            temp = temp->next;
        }

        // Nếu không có giá trị nào trong cả hai danh sách, trả về danh sách rỗng
        if (tempArray.size() == 0)
        {
            return {};
        }

        // Sắp xếp các giá trị trong mảng theo thứ tự tăng dần
        sort(tempArray.begin(), tempArray.end());

        // Tạo lại danh sách liên kết từ mảng đã được sắp xếp
        for (auto it : tempArray)
        {
            insert(result, it);
        }

        return result; // Trả về danh sách liên kết đã được trộn và sắp xếp
    }
};
