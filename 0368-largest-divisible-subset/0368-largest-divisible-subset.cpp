class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1), prev(n,-1);
        int maxLen=0;
        int end=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0 && dp[j]<dp[i]+1){
                    dp[j]=dp[i]+1;
                    prev[j]=i;
                }
            }
            if(dp[i]>maxLen){
                maxLen=dp[i];
                end=i;
            }
        }
        vector<int> ans;
        int i=end;
        while(i!=-1){
            ans.push_back(nums[i]);
            i=prev[i];
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};