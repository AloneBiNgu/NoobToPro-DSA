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
    int hammingWeight(int n)
    {
        string bit = calculateBinary(n);
        int res = 0;

        cout << bit << "\n";
        for (int i = 0; i < bit.length(); i++)
            res += bit[i] - '0';
        return res;
    }
};