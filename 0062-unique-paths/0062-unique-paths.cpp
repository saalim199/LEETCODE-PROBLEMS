class Solution {
public:
    int solve(vector<vector<int>> &dp,int i,int j,int m,int n){
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int d=solve(dp,i+1,j,m,n);
        int r=solve(dp,i,j+1,m,n);
        return dp[i][j]=d+r; 
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(dp,0,0,m,n);
    }
};