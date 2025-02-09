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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return head; // Nếu danh sách rỗng, trả về nullptr

        ListNode *node = nullptr; // Biến lưu trữ node mới sau khi đảo ngược

        // Duyệt qua từng phần tử trong danh sách
        while (head != nullptr)
        {
            ListNode *temp = head->next; // Lưu lại node tiếp theo để tiếp tục duyệt
            head->next = node;           // Đảo chiều liên kết: trỏ node hiện tại về node trước đó
            node = head;                 // Cập nhật node mới đã đảo ngược
            head = temp;                 // Di chuyển con trỏ head tới node tiếp theo
        }

        return node; // Trả về node mới đầu tiên (tức là node cuối cùng ban đầu)
    }
};