class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        string ans="";
        for(int i=0;i<s.size()-1;i++) dp[i][i]=true;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<i;j++){
                if(s[j]==s[i] && (i-j<=2 || dp[j+1][i-1])){
                    // cout<<i<<" "<<j<<endl;
                    dp[j][i]=true;
                    if(ans.size()<=(i-j+1)){
                        ans=s.substr(j,i-j+1);
                    }
                }
            }
        }
        return ans;
    }
};