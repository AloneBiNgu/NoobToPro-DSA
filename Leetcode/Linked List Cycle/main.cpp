// Cách 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;
        unordered_map<ListNode *, int> hashTable;
        while (true)
        {
            hashTable[head] += 1;
            if (hashTable[head] >= 2)
                return true;
            if (head->next == nullptr)
                break;
            ListNode *temp = head->next;
            head->next = nullptr;
            head = temp;
        }
        return false;
    }
};

// Cách 2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;
        unordered_map<ListNode *, int> hashTable;
        hashTable[head] += 1;
        while (true)
        {
            hashTable[head->next] += 1;
            if (hashTable[head->next] >= 2)
                return true;
            if (head->next == nullptr)
                break;
            ListNode *temp = head->next;
            head->next = nullptr;
            head = temp;
        }
        return false;
    }
};

// Cách 3
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
                return true;
        }
        return false;
    }
};