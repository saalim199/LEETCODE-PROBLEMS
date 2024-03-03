class Solution {
public:
    int solve(int i,int b,int fee,vector<int> &p,vector<vector<int>> &dp){
        if(i==p.size()) return 0;
        if(dp[i][b]!=-1) return dp[i][b];
        int profit=0;
        if(b){
            profit=max(-p[i]+solve(i+1,0,fee,p,dp),solve(i+1,1,fee,p,dp));
        }else{
            profit=max(p[i]-fee+solve(i+1,1,fee,p,dp),solve(i+1,0,fee,p,dp));
        }
        return dp[i][b]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(0,1,fee,prices,dp);
    }
};