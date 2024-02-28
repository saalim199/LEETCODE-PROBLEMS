class Solution {
public:
    int solve(int i,int t,vector<int>&nums,vector<vector<int>>&dp){
        if(t==0) return 1;
        if(i==0){
            if(nums[i]==t) return 1;
            return 0;
        }
        if(dp[i][t]!=-1) return dp[i][t];
        int nottaken=solve(i-1,t,nums,dp);
        int taken=0;
        if(nums[i]<t)
            taken=solve(i-1,t-nums[i],nums,dp);
        return dp[i][t]=(nottaken || taken);
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if(total%2!=0) return false;
        vector<vector<int>> dp(nums.size(), vector<int>(total/2+1,-1));
        return solve(nums.size()-1,total/2,nums,dp);

    }
};