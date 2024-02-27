class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&tri,vector<vector<int>>&dp){
        if(i==tri.size()-1) return tri[tri.size()-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down=tri[i][j]+solve(i+1,j,tri,dp);
        int right=tri[i][j]+solve(i+1,j+1,tri,dp);
        return dp[i][j]=min(down,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
        return solve(0,0,triangle,dp);
    }
};