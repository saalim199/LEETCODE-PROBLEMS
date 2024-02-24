class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,int count,int &c,vector<vector<int>> &visited){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return 0;
        if(grid[i][j]==2) {
            cout<<count<<" "<<c<<endl;
            if(count==c) return 1;
            else return 0;
        }
        if(grid[i][j]==-1 || visited[i][j]==1) return 0;
        // if(dp[i][j]!=-1){ return dp[i][j];}
        visited[i][j]=1;
        int r=solve(grid,i,j+1,count+1,c,visited);
        int d=solve(grid,i+1,j,count+1,c,visited);
        int l=solve(grid,i,j-1,count+1,c,visited);
        int u=solve(grid,i-1,j,count+1,c,visited);
        visited[i][j]=0;
        return r+d+l+u;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        // vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int c=0;
        int starti=-1;
        int startj=-1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    starti=i;
                    startj=j;
                }
                if(grid[i][j]==0) c++;
            }
        }
        c++;
        return solve(grid,starti,startj,0,c,visited);
    }
};