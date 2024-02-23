class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        string ans="";
        for(auto c:s){
            mp[c]++;
        }
        for(auto c:order){
            if(mp.find(c)!=mp.end()){
                ans.append(mp[c],c);
                mp.erase(c);
            }
        }
        for(auto it: mp){
            ans.append(it.second,it.first);
        }
        return ans;
    }
};