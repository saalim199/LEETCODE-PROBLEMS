class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double res=0;
        int n=customers.size();
        int t=0;
        for(int i=0;i<n;i++){
            if(t<customers[i][0]){
                t=customers[i][0];
            }
            t+=customers[i][1];
            res+=(t-customers[i][0]);
        }
        return res/n;
    }
};