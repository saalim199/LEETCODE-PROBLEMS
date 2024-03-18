class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        int ans=1;
        int end=points[0][1];
        for(int i=0;i<points.size();i++){
            if(points[i][0]>end){
                ans++;
                end=points[i][1];
            }else{
                end=min(end,points[i][1]);
            }
        }
        return ans;
    }
};