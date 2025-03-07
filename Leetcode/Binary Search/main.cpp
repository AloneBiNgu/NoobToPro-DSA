class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = (right + left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                left++;
            else
                right--;
        }

        return -1;
    }
};

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = (right + left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }

        return -1;
    }
};