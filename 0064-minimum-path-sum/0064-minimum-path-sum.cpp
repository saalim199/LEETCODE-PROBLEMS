class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return grid[0][0];
        if (i < 0 || j < 0)
            return 1e8;
        if (dp[i][j] != 1e8)
            return dp[i][j];
        int up = grid[i][j] + solve(i - 1, j, grid, dp);
        int left = grid[i][j] + solve(i, j - 1, grid, dp);
        return dp[i][j] = min(dp[i][j], min(up, left));
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 1e8));
        return solve(grid.size() - 1, grid[0].size() - 1, grid, dp);
    }
};