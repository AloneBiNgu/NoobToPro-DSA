class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = 0;
        int cnt = 0;
        while (i < nums.size())
        {
            if (i >= nums.size() - cnt)
                break;
            if (nums[i] == 0)
            {
                cnt++;
                nums.push_back(nums[i]);
                nums.erase(nums.begin() + i);
            }
            else
                i++;
        }
        return;
    }
};