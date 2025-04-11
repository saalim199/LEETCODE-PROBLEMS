class Solution {
public:
    bool dfs(int i, vector<int> adj[], vector<int> &vis, vector<int> pathVis){
        cout<<i<<" ";
        vis[i]=1;
        pathVis[i]=1;
        for(auto a:adj[i]){
            if(!vis[a]){
                if(dfs(a,adj,vis,pathVis)){
                    return true;
                }
            }else if(pathVis[a]) return true;
        }
        pathVis[i]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(auto a:pre){
            adj[a[1]].push_back(a[0]);
        }
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis)) return false;
            }
        }
        return true;
    }
};