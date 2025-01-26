class Solution
{
public:
    bool isValid(vector<vector<int>> &image, int row, int col)
    {
        int m = image.size();
        int n = image[0].size();

        return (row >= 0 && col >= 0 && row < m && col < n);
    }
    vector<pair<int, int>> neighbors(vector<vector<int>> &image, int row, int col)
    {
        vector<pair<int, int>> result;
        result.push_back({row + 1, col});
        result.push_back({row - 1, col});
        result.push_back({row, col + 1});
        result.push_back({row, col - 1});

        return result;
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        map<int, map<int, int>> visisted;
        int startColor = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while (!q.empty())
        {
            pair<int, int> top = q.front();
            q.pop();

            int row = top.first;
            int col = top.second;

            if (visisted[row][col] == true)
                continue;
            visisted[row][col] = true;
            image[row][col] = color;

            for (auto it : neighbors(image, row, col))
            {
                if (visisted[it.first][it.second] == true || !isValid(image, it.first, it.second) || image[it.first][it.second] != startColor)
                    continue;
                q.push({it.first, it.second});
            }
        }
        return image;
    }
};

class Solution
{
public:
    bool isValid(vector<vector<int>> &image, int row, int col)
    {
        int m = image.size();
        int n = image[0].size();

        return (row >= 0 && col >= 0 && row < m && col < n);
    }

    void dfs(vector<vector<int>> &image, int sr, int sc, int startColor, int color)
    {
        if (!isValid(image, sr, sc) || image[sr][sc] != startColor || image[sr][sc] == color)
            return;
        image[sr][sc] = color;
        dfs(image, sr + 1, sc, startColor, color);
        dfs(image, sr - 1, sc, startColor, color);
        dfs(image, sr, sc + 1, startColor, color);
        dfs(image, sr, sc - 1, startColor, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int startColor = image[sr][sc];
        dfs(image, sr, sc, startColor, color);
        return image;
    }
};