class Solution {
public:
    //WITH DP SOLUTION
    int solve(vector<int>& nums, int i, vector<int> &dp){
        if(i>=(nums.size()-1)) return 0;
        if(dp[i]!=-1) return dp[i];
        int cnt=0;
        int mini=1e8;
        for(int j=1;j<=nums[i];j++){
            cnt=1+solve(nums,i+j,dp);
            mini=min(mini,cnt);
        }
        return dp[i]=mini;
    }
    int jump(vector<int>& nums) {
        // vector<int> dp(nums.size(),-1);
        // return solve(nums,0,dp);
        int n=nums.size();
        int index=0;
        int maxi=0;
        int ans=0;
        for(int i=0;i<n-1;i++){
            maxi=max(maxi,nums[i]+i);
            if(i==index){
                ans++;
                index=maxi;
                if(index>=n-1) return ans;
            }
        }
        return ans;
    }
};