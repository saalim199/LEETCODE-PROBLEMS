/*
[2,1,1]

[1,1,0]

[0,1,1]
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int totalOranges=0;
        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0) totalOranges++;
                if(grid[i][j]==2) q.push({i,j}); 
            }
        }
        int time=0;
        bool first=1;
        int countOranges=0;
        int rows[4]={1,-1,0,0};
        int cols[4]={0,0,1,-1};
        while(!q.empty()){
            int queueSize=q.size();
            countOranges+=queueSize;
            if(first) {
                first=0;
            }else{
                time++;
            }
            for(int l=0;l<queueSize;l++){
                auto [i,j] = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int row=i+rows[k];
                    int col=j+cols[k];
                    if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1){
                        cout<<row<<" "<<col<<endl;
                        grid[row][col]=2;
                        q.push({row,col});
                    }
                }
            }
        }
        cout<<countOranges<<" "<<totalOranges<<endl;
        if(totalOranges==countOranges) return time;
        return -1;
    }
};