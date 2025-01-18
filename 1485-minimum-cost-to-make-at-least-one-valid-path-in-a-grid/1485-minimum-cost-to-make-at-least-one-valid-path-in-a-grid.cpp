class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> dis(n, vector<bool>(m));
        deque<pair<int, int>> dq;
        vector<vector<int>> dirs = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        dq.push_back({0, 0});
        while (!dq.empty()) {
            auto it = dq.front();
            dq.pop_front();
            int r=it.first/m;
            int c=it.first%m;
            int cost= it.second;
            if (r == n - 1 && c == m - 1)  return cost;
            if (dis[r][c])continue;
            dis[r][c] = true;
            for (int i = 1; i <= 4; i++) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    if (grid[r][c] == i) {
                        dq.push_front({nr * m + nc, cost});
                    } else {
                        dq.push_back({nr * m + nc, cost + 1});
                    }
                }
            }
        }
        return -1;
    }
};