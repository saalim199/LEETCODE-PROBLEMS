class Solution {
public:
    int dfs(int i,int parent, vector<int>& nums, unordered_map<int,vector<int>>& adj, vector<int>& xor_sum, 
    vector<unordered_set<int>>& descendent){
        int cal=0;
        descendent[i].insert(i);
        for(auto &y : adj[i]){
            if(y==parent) continue;
            cal ^= dfs(y,i,nums,adj,xor_sum,descendent);
            descendent[i].insert(descendent[y].begin(),descendent[y].end());
        }
        cal ^=nums[i];
        return xor_sum[i]=cal;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<unordered_set<int>> descendants(n);
        unordered_map<int,vector<int>> adj;
        vector<int> xor_sum(n,-1);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int res=INT_MAX;
        int total_xor = dfs(0,-1,nums,adj,xor_sum,descendants);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
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