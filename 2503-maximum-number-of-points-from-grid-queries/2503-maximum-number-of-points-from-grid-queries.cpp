typedef pair<int, pair<int, int>> pipii;
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        vector<pair<int, int>> sorted_queries;
        for (int i = 0; i < queries.size(); i++) {
            sorted_queries.push_back({queries[i], i});
        }
        sort(sorted_queries.begin(), sorted_queries.end());
        pq.push({grid[0][0], {0, 0}});
        int rows[4] = {-1, 1, 0, 0};
        int cols[4] = {0, 0, -1, 1};
        int i = 0;
        vector<int> ans(queries.size(), 0);
        int cnt = 0;
        while (i < sorted_queries.size()) {
            while (!pq.empty() && pq.top().first < sorted_queries[i].first) {
                pipii e = pq.top();
                int r = e.second.first;
                int c = e.second.second;
                int k = e.first;
                pq.pop();
                if (!vis[r][c]) {
                    cnt++;
                    vis[r][c] = 1;
                    for (int j = 0; j < 4; j++) {
                        int x = r + rows[j];
                        int y = c + cols[j];
                        if (x >= 0 && y >= 0 && x < grid.size() &&
                            y < grid[0].size() && !vis[x][y]) {
                            pq.push({grid[x][y], {x, y}});
                        }
                    }
                }
            }
            ans[sorted_queries[i].second] = cnt;
            i++;
        }
        return ans;
    }
};

