class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // Lấy kích thước của mảng
        int n = nums.size();
        // Tính số lần tối thiểu để một phần tử có thể chiếm đa số
        int minAppear = n / 2;

        // Khởi tạo con trỏ trái và phải, đại diện cho hai đầu của mảng
        int left = 0, right = n - 1;

        // Khởi tạo flag để theo dõi số lần xuất hiện lớn nhất và kết quả
        int flag = INT_MIN;
        int result = nums[0]; // Khởi tạo phần tử kết quả là phần tử đầu tiên của mảng

        // Tạo một unordered_map để đếm số lần xuất hiện của các phần tử
        unordered_map<int, int> m;

        // Đếm số lần xuất hiện của phần tử ở giữa mảng
        m[nums[(right + left) / 2]]++;

        // Duyệt qua mảng từ hai đầu (left và right)
        while (left < right)
        {
            // Đếm số lần xuất hiện của phần tử tại vị trí left và right
            m[nums[left]]++;
            m[nums[right]]++;

            // Kiểm tra nếu số lần xuất hiện của phần tử tại left lớn hơn minAppear
            // và nó xuất hiện nhiều nhất, cập nhật kết quả
            if (m[nums[left]] > minAppear && m[nums[left]] > flag)
            {
                result = nums[left];
                flag = m[nums[left]];
            }

            // Kiểm tra nếu số lần xuất hiện của phần tử tại right lớn hơn minAppear
            // và nó xuất hiện nhiều nhất, cập nhật kết quả
            if (m[nums[right]] > minAppear && m[nums[right]] > flag)
            {
                result = nums[right];
                flag = m[nums[right]];
            }

            // Di chuyển con trỏ về phía nhau (left tăng lên, right giảm đi)
            left++, right--;
        }

        // In ra các phần tử và số lần xuất hiện của chúng (có thể dùng để debug)
        for (auto it : m)
        {
            cout << it.first << " " << it.second << "\n";
        }

        // Trả về kết quả, phần tử chiếm đa số
        return result;
    }
};
