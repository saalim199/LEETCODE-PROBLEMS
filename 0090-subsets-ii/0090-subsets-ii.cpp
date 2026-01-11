class Solution {
public:
    void solve(int i, vector<int>& nums, set<vector<int>>& ans, vector<int> subset){
        if(i==nums.size()){
            sort(subset.begin(),subset.end());
            ans.insert(subset);
            return;
        }
        solve(i+1,nums,ans,subset);
        subset.push_back(nums[i]);
        solve(i+1,nums,ans,subset);
        // subset.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> v;
        vector<int> sub;
        solve(0,nums,ans,sub);
        for(auto &it: ans){
            v.push_back(it);
        }
        return v;
    }
};