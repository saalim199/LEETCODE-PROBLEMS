typedef pair<long long,int> pii;
int mod=1e9+7;
class Solution {
public:
    long long dijkstra(int n, vector<vector<int>>& roads) {
    vector<vector<pii>> adj(n);
    for (const auto& road : roads) {
        adj[road[0]].push_back({road[2], road[1]});
        adj[road[1]].push_back({road[2], road[0]});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<long long> dist(n, LLONG_MAX);
    vector<long long> ways(n,0);
    dist[0] = 0;
    ways[0]=1;
    pq.push({0, 0}); // {distance, node}

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto &[weight, v] : adj[u]) {
            long long newD= dist[u]*1LL + weight;
            if ( newD < dist[v]) {
                dist[v] = newD;
                pq.push({dist[v], v});
                ways[v]=ways[u];
            }else if(newD == dist[v]){
                ways[v]+=ways[u];
                ways[v]%=mod;
            }
        }
    }
    
    return ways[n-1];
}
    int countPaths(int n, vector<vector<int>>& roads) {
        int ans = dijkstra(n,roads);
         return ans;
    }
};