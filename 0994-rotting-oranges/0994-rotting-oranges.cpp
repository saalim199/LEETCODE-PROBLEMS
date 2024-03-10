class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({{i,j},0});
                if(grid[i][j]==1) cnt++;
            }
        }
        int delr[4]={-1,0,1,0};
        int delc[4]={0,1,0,-1};
        int t=0;
        int cnt2=0;
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int tm=q.front().second;
            q.pop();
            t=max(t,tm);
            for(int i=0;i<4;i++){
                int row=x+delr[i];
                int col=y+delc[i];
                if(row>=0 && col>=0 && row<n && col<m && grid[row][col]==1){
                    grid[row][col]=2;
                    cnt2++;
                    q.push({{row,col},tm+1});
                }
            }
        }
        // cout<<cnt<<" "<<cnt2<<endl;
        return cnt2==cnt ? t : -1;
    }
};