class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &mat, vector<vector<int>> &vis){
        vis[i][j]=1;
        int rows[4]={0,1,0,-1};
        int cols[4]={1,0,-1,0};
        for(int k=0;k<4;k++){
            int r=i+rows[k], c=j+cols[k];
            if(r>=0 && c>=0 && r<mat.size() && c<mat[0].size() && mat[r][c]==0 && !vis[r][c]){
                dfs(r,c,mat,vis);
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<vector<int>>mat(n*3,vector<int>(n*3,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int r=i*3, c=j*3;
                if(grid[i][j]=='/'){
                    mat[r][c+2]=1;
                    mat[r+1][c+1]=1;
                    mat[r+2][c]=1;
                }else if(grid[i][j]=='\\'){
                    mat[r][c]=1;
                    mat[r+1][c+1]=1;
                    mat[r+2][c+2]=1;  
                }
            }
        }
        int cnt=0;
        vector<vector<int>> vis(n*3,vector<int>(n*3,0));
        for(int i=0;i<n*3;i++){
            for(int j=0;j<n*3;j++){
                // cout<<mat[i][j];
                if(mat[i][j]==0 && !vis[i][j]){
                    cnt++;
                    dfs(i,j,mat,vis);
                }
            }
            // cout<<endl;
        }
        return cnt;
    }
};