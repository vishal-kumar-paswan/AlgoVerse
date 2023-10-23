class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> s;
        int n = heights.size();
        int m = heights[0].size();
        s.push({0, {0, 0}});
        int di[] = {0, 0, 1, -1};
        int dj[] = {1, -1, 0, 0};
        vector<vector<int>> weight(n, vector<int>(m, INT_MAX));
        while (!s.empty())
        {
            int w = s.top().first;
            int i = s.top().second.first;
            int j = s.top().second.second;
            if (i == n - 1 && j == m - 1)
                return w;
            s.pop();
            for (int x = 0; x < 4; x++)
            {
                int newi = i + di[x];
                int newj = j + dj[x];

                if (newi >= 0 && newi < n && newj >= 0 && newj < m)
                {
                    int diff = abs(heights[i][j] - heights[newi][newj]);
                    if (weight[newi][newj] > (max(w, diff)))
                    {
                        weight[newi][newj] = max(w, diff);
                        s.push({weight[newi][newj], {newi, newj}});
                    }
                }
            }
        }
        return 0;
    }
};