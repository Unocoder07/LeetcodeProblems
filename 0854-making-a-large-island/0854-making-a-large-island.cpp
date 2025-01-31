class Solution {

public:
const static inline std::vector<int> DIRECTIONS = { -1, 0, 1, 0, -1 };
    int largestIsland(vector<vector<int>>& grid) {
         int n = grid.size(); // Dimension of the grid
        std::vector<int> parent(n * n);  // Parent array for Union-Find
        std::vector<int> size(n * n, 1); // Size array for Union-Find
        std::iota(parent.begin(), parent.end(), 0); // Initialize each node as its own parent
      
        // Union-Find Find function using path compression for efficiency
        std::function<int(int)> find;
        find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        // Initial maximum island size, a single cell
        int maxIslandSize = 1;

        // Union islands and compute their sizes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    // Explore all 4 directions
                    for (int k = 0; k < 4; ++k) {
                        int x = i + DIRECTIONS[k], y = j + DIRECTIONS[k + 1];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y]) {
                            int parentA = find(x * n + y);
                            int parentB = find(i * n + j);
                            if (parentA != parentB) {
                                parent[parentA] = parentB;
                                size[parentB] += size[parentA];
                                maxIslandSize = std::max(maxIslandSize, size[parentB]);
                            }
                        }
                    }
                }
            }
        }

        // Try flipping each 0 to a 1 to see if we can get larger island
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j]) {
                    int potentialSize = 1; // Start with the flipped cell itself
                    std::unordered_set<int> visited;

                    // Check all 4 neighboring cells
                    for (int k = 0; k < 4; ++k) {
                        int x = i + DIRECTIONS[k], y = j + DIRECTIONS[k + 1];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y]) {
                            int root = find(x * n + y);
                            // If root hasn't been seen before, count its size
                            if (visited.count(root) == 0) {
                                visited.insert(root);
                                potentialSize += size[root];
                            }
                        }
                    }
                    // Update the maximum island size
                    maxIslandSize = std::max(maxIslandSize, potentialSize);
                }
            }
        }

        // Return the maximum island size found
        return maxIslandSize;
    }
};