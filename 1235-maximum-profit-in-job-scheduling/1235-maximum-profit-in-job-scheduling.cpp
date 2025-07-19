class Solution {
public:
    int solve(int i, vector<vector<int>> &time, vector<int> &dp){
        if(i>=time.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int notTaken = solve(i+1,time,dp);
        int left=i+1;
        int right=time.size();
        while(left<right){
            int mid = (left+right)/2;
            if(time[mid][0]>=time[i][1]) right=mid;
            else left=mid+1;
        }
        int taken = time[i][2] + solve(left,time,dp);
        return dp[i]=max(notTaken,taken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<vector<int>> time;
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++){
            time.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(time.begin(),time.end());
        return solve(0,time,dp);
    }
};
