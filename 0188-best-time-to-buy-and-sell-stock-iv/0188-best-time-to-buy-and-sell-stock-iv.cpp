class Solution {
public:
int solve(int i,int b,int k,vector<int>& p,vector<vector<vector<int>>> &dp){
        if(k<0 || i==p.size()) return 0;
        if(dp[i][b][k]!=-1) return dp[i][b][k];
        int profit=0;
        if(b){
            profit=max(-p[i]+solve(i+1,0,k,p,dp),solve(i+1,1,k,p,dp));
        }else{
            profit=max(p[i]+solve(i+1,1,k-1,p,dp),solve(i+1,0,k,p,dp));
        }
        return dp[i][b][k]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
         vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k,-1)));
        return solve(0,1,k-1,prices,dp);
    }
};