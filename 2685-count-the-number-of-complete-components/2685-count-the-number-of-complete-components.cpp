class Solution {
public:
    int dfs(int i,vector<bool> &vis, vector<int> adj[]){
        vis[i]=true;
        for(auto &edge : adj[i]){
            if(!vis[edge]){
                return 1+dfs(edge,vis,adj);
            }
        }
        return 0;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<bool> vis(n,false);
        int result=0;
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int k=dfs(i,vis,adj);
                if(adj[i].size()>=k) result++;
            }
        }
        return result;
    }
};