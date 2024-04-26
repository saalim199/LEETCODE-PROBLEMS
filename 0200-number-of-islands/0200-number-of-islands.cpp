class Solution {
public:
void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<char>>& grid,int &n,int &m){
        visited[i][j] = true;
        int row[4]={0,0,-1,1};
        int col[4]={-1,1,0,0};
        for(int k = 0; k < 4; k++){
            int nrow=i+row[k];
            int ncol=j+col[k];
            if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && grid[nrow][ncol]=='1' && visited[nrow][ncol]!=true) 
            {
                dfs(nrow,ncol,visited,grid,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,visited,grid,n,m);
                }
            }
        }
        return ans;
    }
};