class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(),0));
        for(int i=0;i<text2.size();i++){
            if(text1[0]==text2[i]) dp[0][i]=1;
            else if(i!=0 && dp[0][i-1]==1) dp[0][i]=1;
        }
        for(int i=0;i<text1.size();i++){
            if(text2[0]==text1[i]) dp[i][0]=1;
            else if(i!=0 && dp[i-1][0]==1) dp[i][0]=1;
        }
        for(int i=1;i<text1.size();i++){
            for(int j=1;j<text2.size();j++){
                if(text1[i]==text2[j]) dp[i][j]=dp[i-1][j-1]+1;
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        // for(int i=0;i<text1.size();i++){
        //     for(int j=0;j<text2.size();j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[text1.size()-1][text2.size()-1];
    }
};