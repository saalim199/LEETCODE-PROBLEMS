class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<int>> &vis){
        vis[i][j]=1;
        int dr[4]={-1,0,0,1};
        int dc[4]={0,-1,1,0};
        for(int k=0;k<4;k++){
            int r=i+dr[k];
            int c=j+dc[k];
            if(r>=0 && c>=0 && r<heights.size() && c<heights[0].size() && heights[i][j]<=heights[r][c] && vis[r][c]!=1){
                vis[r][c]=1;
                dfs(r,c,heights,vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> pvis(n,vector<int>(m,0));
        vector<vector<int>> avis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dfs(0,i,heights, pvis);
            dfs(n-1,i,heights, avis);
        }
        for(int i=0;i<n;i++){
            dfs(i,0,heights, pvis);
            dfs(i,m-1,heights, avis);
        }
        vector<vector<int>> res;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<pvis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<avis[i][j]<<" ";
                if(avis[i][j]==1 && pvis[i][j]==1){
                    res.push_back({i,j});
                }
            }
            // cout<<endl;
        }
        return res;
    }
};