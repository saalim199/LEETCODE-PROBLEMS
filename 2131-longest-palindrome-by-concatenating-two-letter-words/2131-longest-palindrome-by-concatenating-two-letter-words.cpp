class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        int same=0;
        int ans=0;
        for(int i=0;i<words.size();i++){
            if(words[i][0]==words[i][1]){
                same++;
            }

                string rev="";
                rev+=words[i][1];
                rev+=words[i][0];
                if(mp.find(rev)!=mp.end()){
                    mp[rev]--;
                    ans+=4;
                }else{
                    mp[words[i]]++;
                }
        }
        if(same%2==1) ans+=2;
        return ans;
    }
};