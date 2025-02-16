class Solution
{
public:
    string calculateBinary(int n)
    {
        string result;
        while (n > 0)
        {
            result += (n % 2) + '0';
            n /= 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
    vector<int> countBits(int n)
    {
        vector<int> result;
        for (int i = 0; i <= n; i++)
        {
            string bit = calculateBinary(i);
            int res = 0;
            for (int j = 0; j < bit.length(); j++)
            {
                res += bit[j] - '0';
            }

            result.push_back(res);
        }

        return result;
    }
};