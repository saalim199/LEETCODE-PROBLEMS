class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int> freq;
        vector<int> v;
        for(auto &w : word){
            freq[w]++;
        }
        for(auto &it: freq){
            v.push_back(it.second);
        }
        sort(v.begin(),v.end());
        int res=INT_MAX;
        for(int i=0;i<v.size();i++){
            int t=v[i];
            int cnt=0;
            for(int j=0;j<v.size();j++){
                if(v[j]<t) cnt+=v[j];
                if(v[j]>t+k) cnt+=(v[j]-t-k);
            }
            res=min(res,cnt);
        }
        return res;
    }
};