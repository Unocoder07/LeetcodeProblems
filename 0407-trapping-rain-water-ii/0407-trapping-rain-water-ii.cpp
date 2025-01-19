class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
    if (n == 0) return 0;
    int m = heightMap[0].size();
    if (m == 0) return 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                pq.push({heightMap[i][j], {i, j}});
                vis[i][j] = 1;
            }
        }
    }
    int water = 0;
    vector<int> dr = {1, 0, -1, 0};
    vector<int> dc = {0, 1, 0, -1};
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int height = it.first;
        int r = it.second.first;
        int c = it.second.second;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc]) {
                water += max(0, height - heightMap[nr][nc]);
                pq.push({max(height, heightMap[nr][nc]), {nr, nc}});
                vis[nr][nc] = 1;
            }
        }
    }

    return water;
    }
};