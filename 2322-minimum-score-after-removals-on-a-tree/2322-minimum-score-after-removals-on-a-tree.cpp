// class Solution {
// public:
//     int dfs(int i, vector<int>& nums, unordered_map<int,vector<int>>& adj, vector<int>& xor, 
//     vector<unordered_set<int>>& descendent){
//         int cal=0;
//         descendent[i].insert(i)
//         for(auto &y : adj[i]){
//             if(xor[y]==-1){
//                 cal ^= solve(y,nums,adj,xor,descendent);
//             }
//             descendent[i].insert(descendent[y].begin(),descendent[y].end());
//         }
//         cal ^=nums[i];
//         return xor[i]=cal;
//     }
//     int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
//         int n=nums.size();
//         vector<unordered_set<int>> descendent(n);
//         unordered_map<int,vector<int>> adj;
//         vector<int> xor(n,-1);
//         for(auto edge : edges){
//             adj[edge[0]].push_back(edge[1]);
//             adj[edge[1]].push_back(edge[0]);
//         }
//         int res=0;
//         int total_xor = dfs(0,nums,adj,xor,descendent);
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
                
//             }
//         }
//     }
// };
class Solution {
public:
    int dfs(
        int node, 
        int parent, 
        const vector<int>& nums, 
        const vector<vector<int>>& adj, 
        vector<int>& xor_sum,
        vector<unordered_set<int>>& descendants
    ) {
        int total = nums[node];
        descendants[node].insert(node);
        for (int child : adj[node]) {
            if (child == parent) continue;
            total ^= dfs(child, node, nums, adj, xor_sum, descendants);
            descendants[node].insert(descendants[child].begin(), descendants[child].end());
        }
        xor_sum[node] = total;
        return total;
    }
    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (const vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> xor_sum(n, 0);
        vector<unordered_set<int>> descendants(n);
        dfs(0, -1, nums, adj, xor_sum, descendants);
        int total_xor = xor_sum[0];
        int res = INT_MAX;

        // Try every pair of nodes as "roots" of removed subtrees
        for (int i = 1; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (descendants[i].count(j)) {
                    // j is within i's subtree
                    int a = xor_sum[j];
                    int b = xor_sum[i] ^ xor_sum[j];
                    int c = total_xor ^ xor_sum[i];
                    res = min(res, max({a, b, c}) - min({a, b, c}));
                } else if (descendants[j].count(i)) {
                    // i is within j's subtree
                    int a = xor_sum[i];
                    int b = xor_sum[j] ^ xor_sum[i];
                    int c = total_xor ^ xor_sum[j];
                    res = min(res, max({a, b, c}) - min({a, b, c}));
                } else {
                    // i and j are in disjoint subtrees
                    int a = xor_sum[i];
                    int b = xor_sum[j];
                    int c = total_xor ^ xor_sum[i] ^ xor_sum[j];
                    res = min(res, max({a, b, c}) - min({a, b, c}));
                }
            }
        }
        return res;
    }
};