class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size(), m=grid[0].size();
        int half=(n*m)/2;
        vector<int> v;
        int rem=grid[0][0]%x;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int t=grid[i][j]%x;
                if(t!=rem) return -1;
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(),v.end());
        int ele=v[half];
        // cout<<half;
        // cout<<ele<<endl;
        int cnt=0;
        for(auto e:v){
            cnt+=(abs(ele-e)/x);
        }
        return cnt;
    }
};