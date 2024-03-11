class Solution {
public:
    void rec(int i,int j,vector<vector<int>>& image,int old_color,int new_color){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size()
         || image[i][j]!=old_color || image[i][j]==new_color){
             return;
         }
         image[i][j]=new_color;
         rec(i-1,j,image,old_color,new_color);
         rec(i+1,j,image,old_color,new_color);
         rec(i,j+1,image,old_color,new_color);
         rec(i,j-1,image,old_color,new_color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // int n=image.size();
        // int m=image[0].size();
        // queue<pair<int,int>> q;
        // int oldc=image[sr][sc];
        // q.push({sr,sc});
        // image[sr][sc]=color;
        // int drow[4]={-1,0,1,0};
        // int dcol[4]={0,1,0,-1};
        // while(!q.empty()){
        //     int x=q.front().first;
        //     int y=q.front().second;
        //     q.pop();
        //     // cout<<x<<" "<<y<<endl;
        //     for(int i=0;i<4;i++){
        //         int r=x+drow[i];
        //         int c=y+dcol[i];
        //         if(r>=0 && c>=0 && r<n && c<m && image[r][c]!=color && image[r][c]==oldc){
        //             image[r][c]=color;
        //             q.push({r,c});
        //         }
        //     }
        // }

        /// RECURSIVE SOLUTION

        rec(sr,sc,image,image[sr][sc],color);
        return image;
    }
};