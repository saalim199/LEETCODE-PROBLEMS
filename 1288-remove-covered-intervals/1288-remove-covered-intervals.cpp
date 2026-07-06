class Solution {
public:
    static bool comperator(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];     
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comperator);
        vector<int> curr = {intervals[0][0], intervals[0][1]};
        int count = 1;
        for(int i=1; i<intervals.size(); i++){
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            if(intervals[i][0]>=curr[0] && intervals[i][1]<=curr[1]){
                continue;
            }else{
                curr={intervals[i][0],intervals[i][1]};
                count++;
            }
        }
        return count;
    }
};