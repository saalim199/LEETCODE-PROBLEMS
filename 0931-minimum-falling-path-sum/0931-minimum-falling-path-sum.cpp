class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(j-1>=0) dp[i][j]=min(dp[i][j],(matrix[i][j]+dp[i-1][j-1]));
                dp[i][j]=min(dp[i][j],(matrix[i][j]+dp[i-1][j]));
                if(j+1<m) dp[i][j]=min(dp[i][j],(matrix[i][j]+dp[i-1][j+1]));
            }
        }
        int res=INT_MAX;
        for(int i=0;i<m;i++){
            res=min(res,dp[n-1][i]);
        }
        return res;
    }
};