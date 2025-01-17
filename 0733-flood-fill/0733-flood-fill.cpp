class Solution {
    private:
  void dfs(int row, int col, vector<vector<int>>& image, int newColor, int oldColor) {
    int n = image.size();
    int m = image[0].size();
    image[row][col] = newColor;
    vector<int> dr = {1, 0, -1, 0};
    vector<int> dc = {0, -1, 0, 1};
    for (int i = 0; i < 4; i++) {
        int nrow = row + dr[i];
        int ncol = col + dc[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == oldColor) {
            dfs(nrow, ncol, image, newColor, oldColor);
        }
    }
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int oldcolor=image[sr][sc];
        if(color!=oldcolor)
        {
             dfs(sr,sc,image,color,oldcolor);
        }
        return image;
    }
};