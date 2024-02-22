class Solution {
public:
    void solve(int row,vector<vector<string>> &ans,vector<string> &board,vector<int> &ROW,vector<int> &COL,vector<int> &UPPER,vector<int> &LOWER,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
            for(int j=0;j<n;j++){
                if(ROW[row]==0 && COL[j]==0 && UPPER[row+j]==0 && LOWER[(n-1)+j-row]==0){
                    ROW[row]=1;
                    COL[j]=1;
                    UPPER[row+j]=1;
                    LOWER[(n-1)+j-row]=1;
                    board[row][j]='Q';
                    solve(row+1,ans,board,ROW,COL,UPPER,LOWER,n);
                    ROW[row]=0;
                    COL[j]=0;
                    UPPER[row+j]=0;
                    LOWER[(n-1)+j-row]=0;
                    board[row][j]='.';
                }
            }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        vector<int> ROW(n,0);
        vector<int> COL(n,0);
        vector<int> UPPER(2*n-1,0);
        vector<int> LOWER(2*n-1,0);
        solve(0,ans,board,ROW,COL,UPPER,LOWER,n);
        return ans;
    }
};