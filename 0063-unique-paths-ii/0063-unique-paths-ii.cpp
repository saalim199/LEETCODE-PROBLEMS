class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp,int i,int j){
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=solve(obstacleGrid,dp,i-1,j);
        int left=solve(obstacleGrid,dp,i,j-1);
        return dp[i][j]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(),-1));
        return solve(obstacleGrid,dp,obstacleGrid.size()-1,obstacleGrid[0].size()-1);
    }
};