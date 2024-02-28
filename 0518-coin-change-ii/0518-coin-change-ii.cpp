class Solution {
public:
    int solve(int i,int target,vector<int>& nums,vector<vector<int>>&dp){
        if(i==0){
            return (target%nums[0]==0);
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int notTaken=solve(i-1,target,nums,dp);
        int taken=0;
        if(nums[i]<=target) taken=solve(i,target-nums[i],nums,dp);
        return dp[i][target]=(notTaken+taken);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return solve(coins.size()-1,amount,coins,dp);
    }
};