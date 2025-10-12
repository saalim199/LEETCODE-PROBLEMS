class Solution {
public:
    int longestBalanced(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int> mp;
            for(int j=i;j<s.size();j++){
                mp[s[j]]++;
                int cnt=mp[s[j]];
                int flag=true;
                for(auto it: mp){
                    if(it.second!=cnt){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};