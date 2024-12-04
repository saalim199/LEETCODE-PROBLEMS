class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);
        ans[0].push_back({1});
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j==0) ans[i].push_back(1);
                else if(j==i) ans[i].push_back(1);
                else if(j==1) ans[i].push_back(i);
                else if(j==i-1) ans[i].push_back(i);
                else{
                    int t=ans[i-1][j-1]+ans[i-1][j];
                    ans[i].push_back(t);
                }
            }
        }
        return ans;
    }
};