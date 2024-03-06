class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        vector<int> count(nums.size(),1);
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[i]==1+dp[j]){
                        count[i]=count[i]+count[j];
                    }else if(dp[i]<1+dp[j]){
                        dp[i]=1+dp[j];
                        count[i]=count[j];
                    }
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int c=0;
        for(int i=0;i<nums.size();i++){
            cout<<dp[i]<<" ";
            if(dp[i]==maxi){
                c+=count[i];
            }
        }
        cout<<endl;
        for(auto i:count){
            cout<<i<<" ";
        }
        return c;
    }
};