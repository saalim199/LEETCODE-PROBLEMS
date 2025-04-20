class Solution {
public:
    int numRabbits(vector<int>& a) {
        unordered_map<int,int> mp;
        int cnt=0;
        for(int i=0;i<a.size();i++){
            mp[a[i]]++;
        }
        for(auto &[a,b]:mp){
            cnt+=ceil((double)b/(a+1))*(a+1);
        }
        return cnt;
    }
};