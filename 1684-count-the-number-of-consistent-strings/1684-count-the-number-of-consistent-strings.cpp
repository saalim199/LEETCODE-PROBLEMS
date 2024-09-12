class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char,int> mp;
        for(int i=0;i<allowed.size();i++){
            mp[allowed[i]]++;
        }
        int cnt=0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                if(mp.find(words[i][j])==mp.end()){
                    break;
                }
                if(j==words[i].size()-1) cnt++;
            }
        }
        return cnt;
    }
};