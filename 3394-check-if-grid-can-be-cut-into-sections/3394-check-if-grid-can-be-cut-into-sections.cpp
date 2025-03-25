class Solution {
public:
    bool solve(vector<pair<int,int>> &x){
        int cnt=0;
        int last=x[0].second;
        for(int i=1;i<x.size();i++){
            auto &[x1,x2]=x[i];
            if(last>x1){
                if(last<x2){
                    last=x2;
                }
            }else{
                cnt++;
                last=x2;
            }
        }
        if(cnt>=2) return true;
        return false;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> x;
        vector<pair<int,int>> y;
        for(auto r : rectangles){
            int x1=r[0], y1=r[1], x2=r[2], y2=r[3];
            x.push_back({x1,x2});
            y.push_back({y1,y2});
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        if(solve(x)) return true;
        if(solve(y)) return true;
        return false; 
    }
};