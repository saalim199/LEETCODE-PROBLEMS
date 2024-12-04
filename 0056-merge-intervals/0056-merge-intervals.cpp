class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        int j=0;
        res.push_back({intervals[0][0],intervals[0][1]});
        for(int i=1;i<n;i++){
            if(res[j][1]>=intervals[i][0]){
                if(res[j][1]<intervals[i][1]){
                    res[j][1]=intervals[i][1];
                }
            }else{
                res.push_back({intervals[i][0],intervals[i][1]});
                j++;
            }
        }
        return res;
    }
};