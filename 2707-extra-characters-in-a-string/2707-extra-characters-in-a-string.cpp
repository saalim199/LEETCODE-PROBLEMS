class Solution {
public:
    int solve(string &s, int i, unordered_map<string,int> &mp, vector<int> &dp){
        if(i>=s.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int extra=INT_MAX;
        string t="";
        for(int j=i;j<s.size();j++){
            t+=s[j];
            if(mp[t]>0){
                extra=min(extra,solve(s,j+1,mp,dp));
            }
        }
        extra=min(extra,1+solve(s,i+1,mp,dp));
        return dp[i]=extra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int> mp;
        vector<int> dp(s.size(),-1);
        for(auto w: dictionary){
            mp[w]++;
        }
        return solve(s,0,mp,dp);
    }
};