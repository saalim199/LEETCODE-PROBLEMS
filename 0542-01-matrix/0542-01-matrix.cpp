class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int dr[4]={-1,0,0,1};
        int dc[4]={0,1,-1,0};
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int t=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int r=x+dr[i];
                int c=y+dc[i];
                if(r>=0 && c>=0 && r<n && c<m && !vis[r][c]){
                    vis[r][c]=1;
                    mat[r][c]=t+1;
                    q.push({{r,c},t+1});
                }
            }
        }
        return mat;
    }
};