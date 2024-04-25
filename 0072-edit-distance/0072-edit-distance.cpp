class Solution {
public:
    int solve(int i, int j, string &s1, string &s2){
        //base
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(s1[i]==s2[j]) return solve(i-1,j-1,s1,s2);
        else{
            int ins=solve(i,j-1,s1,s2);
            int del=solve(i-1,j,s1,s2);
            int rep=solve(i-1,j-1,s1,s2);
            return 1+min(ins,min(del,rep));
        }
    }
    int minDistance(string s1, string s2) {
        if(s1.size()==0) return s2.size();
        if(s2.size()==0) return s1.size();
        return solve(s1.size()-1,s2.size()-1,s1,s2);
        // vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
        // for(int i=0;i<s1.size();i++){
        //     dp[i][0]=i;
        // }
        // for(int j=1;j<s2.size();j++){
        //     dp[0][j]=j;
        // }
        // for(int i=0;i<s1.size();i++){
        //     for(int j=0;j<s2.size();j++){
        //         if(s1[i]==s2[j]){
        //             dp[i+1][j+1]=0+dp[i][j];
        //         }else{
        //             dp[i+1][j+1]=1+min(dp[i][j+1],min(dp[i+1][j],dp[i][j]));
        //         }
        //     }
        // }
        // return dp[s1.size()][s2.size()];
    }
};