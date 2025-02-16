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
    bool isPalindrome(ListNode *head)
    {
        unordered_map<int, ListNode *> hashMap;
        while (true)
        {
            hashMap.insert({hashMap.size(), head});
            if (head->next == nullptr)
                break;
            head = head->next;
        }

        int i = 0, j = hashMap.size() - 1;
        while (i < j)
        {
            cout << hashMap[i]->val << " " << hashMap[j]->val << "\n";
            if (hashMap[i]->val != hashMap[j]->val)
                return false;
            i++, j--;
        }

        return true;
    }
};