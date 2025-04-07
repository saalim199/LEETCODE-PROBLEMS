class Solution {
public:
    bool dfs(int i, vector<int> adj[], vector<int> &vis, vector<int> &visPath){
        vis[i]=1;
        visPath[i]=1;
        for(auto node: adj[i]){
            if(!vis[node]){
                if(dfs(node,adj,vis,visPath)) return true;
            }
            else if(visPath[node]) return true;
        }
        visPath[i]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int> vis(n,0);
        vector<int> visPath(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,visPath)) return false;
            }
        }
        return true;
    }
};