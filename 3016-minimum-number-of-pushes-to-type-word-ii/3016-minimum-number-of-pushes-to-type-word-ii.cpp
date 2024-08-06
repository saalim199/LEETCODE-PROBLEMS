class Solution {
public:
    static bool cmp(pair<char, int>& a, pair<char, int>& b) 
        { 
            return a.second > b.second; 
        } 
    int minimumPushes(string word) {
        int mul=1;
        int cnt=8;
        int res=0;
        unordered_map<char,int> mp;
        for(int i=0;i<word.size();i++){
            mp[word[i]]++;
        }
        vector<pair<char, int> > A; 
        for(auto &it:mp){
            A.push_back(it);
        }
        sort(A.begin(),A.end(),cmp);
        for(auto &a : A){
            if(cnt==0){
                mul++;
                cnt=8;
            }
            cnt--;
            res+=(a.second*mul);
        }
        return res;
    }
};