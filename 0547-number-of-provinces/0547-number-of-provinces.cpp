class Solution {
public:
    void dfs(int i,vector<int> adj[],vector<int> &vis){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]) dfs(it,adj,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& iC) {
        vector<int> adj[iC.size()];
        for(int i=0;i<iC.size();i++){
            for(int j=0;j<iC[i].size();j++){
                if(i!=j && iC[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        // for(int i=0;i<iC.size();i++){
        //     for(auto it:adj[i]) cout<<it<<" ";
        //     cout<<endl;
        // }
        vector<int> vis(iC.size(),0);
        int ans=0;
        for(int i=0;i<iC.size();i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans;
    }
};