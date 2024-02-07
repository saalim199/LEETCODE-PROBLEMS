class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        multimap<int,char, greater<int>> mm;
        string ans="";
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for (auto& it : mp) {
        mm.insert({ it.second, it.first });
        }
        for(auto it:mm){
            ans.append(it.first,it.second);
        }
        return ans;
    }
};