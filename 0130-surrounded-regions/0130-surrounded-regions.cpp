class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>& vis){
        vis[i][j]=1;
        int dr[4]={-1,0,0,1};
        int dc[4]={0,-1,1,0};
        for(int k=0;k<4;k++){
            int x=i+dr[k];
            int y=j+dc[k];
            if(x>=0 && y>=0 && (x<board.size()) && (y<board[0].size()) && !vis[x][y] && board[x][y]=='O'){
                vis[x][y]=1;
                dfs(x,y,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O')
                dfs(i,0,board,vis);
            if(board[i][m-1]=='O')
                dfs(i,m-1,board,vis);
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O')
                dfs(0,i,board,vis);
            if(board[n-1][i]=='O')
                dfs(board.size()-1,i,board,vis);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                // cout<<vis[i][j]<<" ";
                if(board[i][j]=='O' && vis[i][j]==0) board[i][j]='X';
            }
            // cout<<endl;
        }
    }
};