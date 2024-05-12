class Solution {
public:
    int solve(vector<int>& energy, int k, int i, vector<int> &dp){
        if(i>=energy.size()) return 0;
        if(dp[i]!=INT_MIN) return dp[i];
        int taken=energy[i]+solve(energy,k,i+k,dp);
        return dp[i]=taken;
    }
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> dp(energy.size(),INT_MIN);
        int ans=INT_MIN;
        for(int i=0;i<energy.size();i++){
            ans=max(ans,solve(energy,k,i,dp));
        }
        return ans;
    }
};