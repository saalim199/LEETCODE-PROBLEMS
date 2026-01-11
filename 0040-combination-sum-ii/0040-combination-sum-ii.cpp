class Solution {
public:
    void solve(vector<int>& candidates, int target, int i, vector<vector<int>>& ans, vector<int>& ds, int sum) {
    if (sum == target) {  // Found a valid subset
        ans.push_back(ds);
        return;
    }
    if (i == candidates.size() || sum > target) return;  // Out of bounds or sum exceeds target

    for (int j = i; j < candidates.size(); j++) {
        if (j > i && candidates[j] == candidates[j - 1]) continue;  // Skip duplicates
        ds.push_back(candidates[j]);
        solve(candidates, target, j + 1, ans, ds, sum + candidates[j]);
        ds.pop_back();  // Backtrack
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates
    vector<vector<int>> ans;
    vector<int> ds;
    solve(candidates, target, 0, ans, ds, 0);
    return ans;
        return ans;
    }
};