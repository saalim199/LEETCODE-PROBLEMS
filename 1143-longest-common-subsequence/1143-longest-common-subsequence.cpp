class Solution {
public:
    // int solve(string& t1, string& t2, int i, int j, vector<vector<int>>& dp) {
    //     if (i < 0 || j < 0)
    //         return 0;
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     if (t1[i] == t2[j])
    //         dp[i][j] = 1 + solve(t1, t2, i - 1, j - 1, dp);
    //     else
    //         dp[i][j] =
    //             max(solve(t1, t2, i, j - 1, dp), solve(t1, t2, i - 1, j, dp));
    //     return dp[i][j];
    // }
    int longestCommonSubsequence(string t1, string t2) {
        // vector<vector<int>> dp(t1.size()+1, vector<int>(t2.size()+1, 0));
        vector<int> prev(t2.size()+1,0);
        for(int i=0;i<t1.size();i++){
            vector<int> curr(t2.size()+1,0);
            for(int j=0;j<t2.size();j++){
                if(t1[i]==t2[j]){
                    curr[j+1]=prev[j]+1;
                }else{
                    curr[j+1]=max(prev[j+1],curr[j]);
                }
            }
            prev=curr;
        }
        return prev[t2.size()];
        // return solve(t1, t2, t1.size() - 1, t2.size() - 1, dp);
    }
};