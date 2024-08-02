class Solution {
public:
    // int solve(vector<int>& nums, int i,vector<int> &dp){
    //     if(i>=nums.size()){
    //         return 0;
    //     }
    //     if(i==(nums.size()-1)){
    //         return dp[i]=1;
    //     }
    //     if(dp[i]!=-1) return dp[i];
    //     for(int k=1;k<=nums[i];k++){
    //         dp[i]=solve(nums,i+k,dp);
    //     } 
    //     return 0;
    // }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            if(maxi<i) return false;
            maxi=max(maxi,i+nums[i]);
        }
        return true;
    }
};