class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> mp;
        for(int i=0;i<logs.size();i++){
            mp[logs[i][0]]++;
            mp[logs[i][1]]--;
        }
        int maxi=0,year_min=0;
        int c=0;
        for(auto it:mp){
            c+=it.second;
            if(c>maxi){
                maxi=c;
                year_min=it.first;
            }
        }
        return year_min;
    }
};