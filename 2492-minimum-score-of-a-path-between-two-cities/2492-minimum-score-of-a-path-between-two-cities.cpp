class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<bool> vis(n+1,false);
        queue<int> q;
        int ans = INT_MAX;
        q.push(1);
        vis[1] = true;
        for(auto &r : roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto &[neigh,w] : adj[top]){
                ans = min(ans,w);
                if(!vis[neigh]){
                    q.push(neigh);
                    vis[neigh] = true;
                }
            }
        }
        return ans;
    }
};