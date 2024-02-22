class Solution {
public:
    bool solve(vector<vector<char>> &board,string word,int i,int j,int k,int n,int m){
        if(k==word.size()) return true;
        if(i<0 || j<0 || i==n || j==m || board[i][j]!=word[k]) return false;
        char ch=board[i][j];
        board[i][j]='-1';
        bool o1=solve(board,word,i+1,j,k+1,n,m);
        bool o2=solve(board,word,i-1,j,k+1,n,m);
        bool o3=solve(board,word,i,j+1,k+1,n,m);
        bool o4=solve(board,word,i,j-1,k+1,n,m);
        board[i][j]=ch;
        return o1 || o2 || o3 || o4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool found=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    found=solve(board,word,i,j,0,board.size(),board[i].size());
                }
                if(found) return true;
            }
        }
        return false;
    }
};