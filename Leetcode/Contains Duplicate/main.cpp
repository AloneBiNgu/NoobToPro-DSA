class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> hashMap; // Sử dụng unordered_map để lưu trữ số lần xuất hiện của từng phần tử
        for (auto i : nums)
        {                       // Duyệt qua từng phần tử trong mảng
            hashMap[i]++;       // Tăng số lần xuất hiện của phần tử i
            if (hashMap[i] > 1) // Nếu phần tử xuất hiện lần thứ hai, trả về true
                return true;
        }
        return false; // Nếu không có phần tử nào bị trùng, trả về false
    }
};
