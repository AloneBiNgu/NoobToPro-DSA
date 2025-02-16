class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> hashMap;

        for (auto i : nums)
            hashMap[i]++;

        for (auto i : nums)
        {
            if (hashMap[i] == 1)
                return i;
        }

        return nums[0];
    }
};