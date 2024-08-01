class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int l=0;
        int res=0;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            maxi=max(maxi,mp[s[i]]);
            if(i-l+1-maxi>k){
                mp[s[l]]--;
                l++;
            }
            res=max(res,i-l+1);
        }
        return res;
    }
};