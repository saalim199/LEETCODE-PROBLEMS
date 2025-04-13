class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        vector<int> color(graph.size(),-1);
        q.push(0);
        color[0]=0;
        while(!q.empty()){
            int node=q.front();
            int nodeColor=color[node];
            q.pop();
            for(auto adj: graph[node]){
                if(color[adj]==-1){
                    q.push(adj);
                    color[adj]=!nodeColor;
                }else if(color[adj]==nodeColor){
                    return false;
                }
            }
        }
        return true;
    }
};