class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        vector<vector<int>> dp(s.size()+1,vector<int>(r.size()+1,0));
        for(int i=0;i<s.size();i++){
            for(int j=0;j<r.size();j++){
                if(s[i]==r[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                }else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[s.size()][s.size()];
    }
};