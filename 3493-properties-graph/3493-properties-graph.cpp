class Solution {
public:
    void dfs(int i, vector<int> adj[], vector<int> &vis){
        vis[i]=1;
        for(auto a : adj[i]){
            if(!vis[a]) dfs(a,adj,vis);
        }
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n=properties.size();
        vector<int> adj[n];
        vector<int> vis(n,0);
        vector<set<int>> vs;
        for(int i=0;i<properties.size();i++){
            set<int> s(properties[i].begin(),properties[i].end());
            vs.push_back(s);
        }
        for(int i=0;i<vs.size();i++){
            for(int j=i+1;j<vs.size();j++){
                int cnt=0;
                for(auto &a : vs[i]){
                    if(vs[j].find(a)!=vs[j].end()){
                        cnt++;
                        if(cnt>=k) break;
                    }
                }
                if(cnt>=k){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,adj,vis);
            }
        }
        return ans;
    }
};