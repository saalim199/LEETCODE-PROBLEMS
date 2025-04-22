class Solution {
public:
    int solve(int i, int j, string word1, string word2, vector<vector<int>> &dp){
        if(j>=word2.size()){
            return word1.size()-i;
        }
        if(i>=word1.size()){
            return word2.size()-j;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return solve(i+1,j+1,word1,word2,dp);
        int in=solve(i,j+1,word1,word2,dp);
        int dlt=solve(i+1,j,word1,word2,dp);
        int rep=solve(i+1,j+1,word1,word2,dp);
        return dp[i][j]=1+min({in,dlt,rep});
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return solve(0,0,word1,word2,dp);
    }
};