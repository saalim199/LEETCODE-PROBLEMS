class Solution {
public:
    int solve(int i, vector<int> &nums, int half,vector<vector<int>> &dp){
        if(i>=nums.size()){
            if(half==0) return true;
            return false;
        }
        if(half==0) return true;
        if(dp[i][half]!=-1) return dp[i][half];
        int t=0;
        if(nums[i]<=half) t=solve(i+1,nums,half-nums[i],dp);
        int nt=solve(i+1,nums,half,dp);
        return dp[i][half]=(t||nt);
    }
    bool canPartition(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total&1) return false;
        vector<vector<int>> dp(nums.size(),vector<int>(total/2+1,-1));
        bool res= solve(0,nums,total/2,dp);
        return res;
    }
};