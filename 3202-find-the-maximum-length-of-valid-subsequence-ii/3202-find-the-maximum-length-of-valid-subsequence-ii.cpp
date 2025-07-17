class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int maxi=0;
        vector<vector<int>> dp(k,vector<int>(k,0));
        for(auto &num : nums){
            for(int i=0;i<k;i++){
                int mod = num%k;
                dp[i][mod] = dp[mod][i] +1;
                maxi=max(maxi,dp[i][mod]);
            }
        }
        return maxi;
    }
};