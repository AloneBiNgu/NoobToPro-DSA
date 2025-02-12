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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = new ListNode(head->val, head->next);
        int nodeSize = 0;
        while (head->next != nullptr)
        {
            nodeSize++;
            head = head->next;
        }

        int mid = nodeSize / 2;
        if (nodeSize % 2 != 0)
            mid += 1;

        while (temp->next != nullptr && mid > 0)
        {
            temp = temp->next;
            mid--;
        }

        return temp;
    }
};