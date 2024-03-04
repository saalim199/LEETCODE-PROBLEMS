class Solution {
public:
    bool static comp(const string &s1,const string &s2){
        return s1.size()<s2.size();
    }
    bool compareString(string s1,string s2){
        if(s1.size()!=s2.size()+1) return false;
        int i=0,j=0;
        while(i!=s1.size()){
            if(j<s2.size() && s1[i]==s2[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        if(i==s1.size() && j==s2.size()) return true;
        else return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        vector<int> dp(words.size(),1);
        int maxi=0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(compareString(words[i],words[j]) && dp[i]<1+dp[j]){
                    dp[i]=dp[j]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};