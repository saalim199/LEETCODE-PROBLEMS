class Solution {
public:
    int solve(int i,int a,vector<int> &coins,vector<vector<int>>&dp){
        if(i==0){
            if(a%coins[0]==0) return a/coins[0];
            return 1e9;
        }
        if(dp[i][a]!=-1) return dp[i][a];
        int n=0+solve(i-1,a,coins,dp);
        int t=1e9;
        if(coins[i]<=a){
            t=1+solve(i,a-coins[i],coins,dp);
        }
        return dp[i][a]=min(n,t);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int k= solve(coins.size()-1,amount,coins,dp);
        if(k==1e9) return -1;
        else return k;
    }
};