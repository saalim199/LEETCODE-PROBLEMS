class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int>& nums,int i,vector<int> temp){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(ans,nums,i+1,temp);
        temp.pop_back();
        solve(ans,nums,i+1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(ans,nums,0,temp);
        return ans;
    }
};