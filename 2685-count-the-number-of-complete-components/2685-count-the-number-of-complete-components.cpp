class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<bool> vis(n,false);
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            q.push(i);
            vis[i]=true;
            // vector<int> component;
            int m=0;
            int cnt =0;
            while(!q.empty()){
                int ele = q.front();
                q.pop();
                m++;
                // component.push_back(ele);
                for(auto &neigh : adj[ele]){
                    cnt++;
                    if(!vis[neigh]){
                        q.push(neigh);
                        vis[neigh]=true;
                    }
                }
            }
            // bool isComplete = true;
            // for(auto &node : component){
            //     if(adj[node].size() != component.size()-1){
            //         isComplete = false;
            //         break;
            //     }
            // }
            // if(isComplete) ans++;
            if((cnt/2) == ((m*(m-1))/2)) ans++;
        }
        return ans;
    }
};