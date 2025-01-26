# Flood Fill Solution Explanation

Bài toán **Flood Fill** yêu cầu thay đổi màu của một vùng liền kề trong ảnh, bắt đầu từ một điểm cụ thể, với một màu mới. Dưới đây là hai cách tiếp cận giải bài toán này: sử dụng thuật toán BFS và DFS.

## Cách 1: Sử dụng BFS (Breadth-First Search)

### Đoạn mã

```cpp
class Solution
{
public:
    // Kiểm tra xem (row, col) có nằm trong giới hạn của ảnh hay không
    bool isValid(vector<vector<int>> &image, int row, int col)
    {
        int m = image.size();
        int n = image[0].size();

        return (row >= 0 && col >= 0 && row < m && col < n);
    }

    // Lấy danh sách các ô liền kề (trên, dưới, trái, phải)
    vector<pair<int, int>> neighbors(vector<vector<int>> &image, int row, int col)
    {
        vector<pair<int, int>> result;
        result.push_back({row + 1, col});
        result.push_back({row - 1, col});
        result.push_back({row, col + 1});
        result.push_back({row, col - 1});

        return result;
    }

    // Thuật toán Flood Fill sử dụng BFS
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        // Tạo một bảng đánh dấu các ô đã được thăm
        map<int, map<int, int>> visisted;
        // Lấy màu ban đầu tại điểm xuất phát
        int startColor = image[sr][sc];
        // Khởi tạo hàng đợi để duyệt BFS
        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty())
        {
            // Lấy phần tử đầu tiên trong hàng đợi
            pair<int, int> top = q.front();
            q.pop();

            int row = top.first;
            int col = top.second;

            // Nếu ô đã được thăm, bỏ qua
            if (visisted[row][col] == true)
                continue;

            // Đánh dấu ô hiện tại là đã thăm
            visisted[row][col] = true;
            // Đổi màu của ô hiện tại
            image[row][col] = color;

            // Duyệt qua các ô hàng xóm
            for (auto it : neighbors(image, row, col))
            {
                // Bỏ qua nếu ô không hợp lệ, đã thăm hoặc không cùng màu ban đầu
                if (visisted[it.first][it.second] == true || !isValid(image, it.first, it.second) || image[it.first][it.second] != startColor)
                    continue;
                // Thêm ô vào hàng đợi
                q.push({it.first, it.second});
            }
        }
        return image;
    }
};
```

### Giải thích

1. **Xác định vùng hợp lệ**:

    - Hàm `isValid` kiểm tra nếu một ô (row, col) nằm trong giới hạn của ảnh.

2. **Tìm hàng xóm**:

    - Hàm `neighbors` trả về danh sách các ô liền kề (trên, dưới, trái, phải).

3. **BFS**:
    - Sử dụng hàng đợi (`queue`) để duyệt qua tất cả các ô liền kề với màu ban đầu (`startColor`).
    - Với mỗi ô được duyệt, kiểm tra nếu ô đó đã được thăm hoặc không hợp lệ. Nếu hợp lệ, đổi màu của ô và thêm ô vào hàng đợi.

### Phân tích thuật toán

-   **Phức tạp thời gian**: O(m \* n), trong đó `m` là số hàng và `n` là số cột của ảnh.
-   **Phức tạp không gian**: O(m \* n), do cần lưu trạng thái thăm của từng ô.

---

## Cách 2: Sử dụng DFS (Depth-First Search)

### Đoạn mã

```cpp
class Solution
{
public:
    // Kiểm tra xem (row, col) có nằm trong giới hạn của ảnh hay không
    bool isValid(vector<vector<int>> &image, int row, int col)
    {
        int m = image.size();
        int n = image[0].size();

        return (row >= 0 && col >= 0 && row < m && col < n);
    }

    // Hàm đệ quy để duyệt DFS
    void dfs(vector<vector<int>> &image, int sr, int sc, int startColor, int color)
    {
        // Nếu ô không hợp lệ, không cùng màu ban đầu hoặc đã được đổi màu, dừng lại
        if (!isValid(image, sr, sc) || image[sr][sc] != startColor || image[sr][sc] == color)
            return;

        // Đổi màu của ô hiện tại
        image[sr][sc] = color;

        // Gọi đệ quy cho các ô hàng xóm (trên, dưới, trái, phải)
        dfs(image, sr + 1, sc, startColor, color);
        dfs(image, sr - 1, sc, startColor, color);
        dfs(image, sr, sc + 1, startColor, color);
        dfs(image, sr, sc - 1, startColor, color);
    }

    // Thuật toán Flood Fill sử dụng DFS
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        // Lấy màu ban đầu tại điểm xuất phát
        int startColor = image[sr][sc];
        // Bắt đầu đệ quy từ điểm xuất phát
        dfs(image, sr, sc, startColor, color);
        return image;
    }
};
```

### Giải thích

1. **Xác định vùng hợp lệ**:

    - Hàm `isValid` kiểm tra nếu một ô (row, col) nằm trong giới hạn của ảnh.

2. **DFS**:
    - Hàm `dfs` duyệt đệ quy qua tất cả các ô liền kề với màu ban đầu (`startColor`).
    - Nếu một ô không hợp lệ, có màu khác `startColor`, hoặc đã được đổi màu, thì dừng lại.

### Phân tích thuật toán

-   **Phức tạp thời gian**: O(m \* n), tương tự BFS.
-   **Phức tạp không gian**: O(m \* n), do ngăn xếp đệ quy.

---

## Tổng kết

-   **Cách 1** (BFS): Thích hợp nếu ưu tiên duyệt theo cấp độ (layer-wise).
-   **Cách 2** (DFS): Phù hợp khi cần giải quyết bài toán một cách tự nhiên thông qua đệ quy.

Cả hai cách đều đổi màu của vùng liền kề một cách chính xác và đảm bảo đúng yêu cầu bài toán.
