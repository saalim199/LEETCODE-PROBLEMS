class Solution {
public:
    int solve(int i, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(i==coins.size()-1){
            if(amount%coins[i]==0) return amount/coins[i];
            return 1e9;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int taken=1e9;
        if(coins[i]<=amount) taken=1+solve(i,amount-coins[i],coins,dp);
        int notTaken=solve(i+1,amount,coins,dp);
        return dp[i][amount]=min(taken,notTaken);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=solve(0,amount,coins,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};