class Solution {
public:
    int solve(int m,int n,int i, int j, vector<vector<int>> &dp){
        if(i>=m || j>=n || i<0 || j<0) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int down=solve(m,n,i+1,j,dp);
        int up=solve(m,n,i,j+1,dp);
        return dp[i][j]=down+up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m,n,0,0,dp);
    }
};