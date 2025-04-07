class Solution {
public:
    bool solve(int i, vector<vector<int>> &dp, vector<int> &nums, int half){
        if(i>=nums.size() || half<0) return false;
        if(half==0) return true;
        if(dp[i][half]!=-1) return dp[i][half];
        bool taken=(i+1,dp,nums,half-nums[i]);
        bool notTaken=(i+1,dp,nums,half);
        return dp[i][half] = taken || notTaken;
    }
    bool canPartition(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total&1) return false;
        int half=total/2;
        vector<vector<int>> dp(nums.size(),vector<int>(half+1,-1));
        return solve(0,dp,nums,half);
    }
};