class Solution {
public:
    bool checkValid(vector<string> &board, int row, int col){
        int n=board.size();
        //check right of the row
        for(int i=col+1;i<n;i++){
            if(board[row][i]=='Q') return false;
        }
        //check left of the row
        for(int i=col-1;i>=0;i--){
            if(board[row][i]=='Q') return false;
        }
        //check top of the col
        for(int i=row-1;i>=0;i--){
            if(board[i][col]=='Q') return false;
        }
        //check bottom col
        for(int i=row+1;i<n;i++){
            if(board[i][col]=='Q') return false;
        }
        //diagonal up right
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q') return false;
        }
        //diagonal up left
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }
        //diagonal down right
        for(int i=row+1,j=col+1;i<n && j<n;i++,j++){
            if(board[i][j]=='Q') return false;
        }
        //diagonal up left
        for(int i=row+1,j=col-1;i<n && j>=0;i++,j--){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    void helper(vector<string> &board, vector<vector<string>> &ans, int index){
        if(index==board.size()){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<board.size();i++){
            if(checkValid(board,index,i)){
                board[index][i]='Q';
                helper(board,ans,index+1);
                board[index][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        helper(board,ans,0);
        return ans;
    }
};