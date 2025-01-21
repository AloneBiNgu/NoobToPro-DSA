// The time complexity is O(n ^ 2) and the space complexity is O(1).
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }

        return {};
    }
};

// The time complexity is O(n) and the space complexity is O(n).
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            int val = target - nums[i];
            if (m.count(val))
            {
                return {i, m[val]};
            }

            m[nums[i]] = i;
        }

        return {};
    }
};