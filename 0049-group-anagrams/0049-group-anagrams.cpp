class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string w=strs[i];
               sort(w.begin(),w.end());
               mp[w].push_back(strs[i]);
        }
        for(auto &it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};