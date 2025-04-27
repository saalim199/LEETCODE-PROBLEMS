class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(i>=grid.size() || j>=grid[0].size()){
            return 1e9;
        }
        if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];
        if(dp[i][j]!=1e9) return dp[i][j];
        int down=grid[i][j]+solve(i+1,j,grid,dp);
        int right=grid[i][j]+solve(i,j+1,grid,dp);
        return dp[i][j]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
       vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),1e9));
       return solve(0,0,grid,dp);
    //    for(int i=0;i<dp.size();i++){
    //     for(int j=0;j<grid[0].size();j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    //    
    }
};