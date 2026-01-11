class Solution {
public:
    void helper(int index,vector<int>& candidates,set<vector<int>>&ans,vector<int> temp, int target){
        if(index>=candidates.size() || target==0){
            if(target==0){
                sort(temp.begin(),temp.end());
                ans.insert(temp);
            }
            return;
        }
        helper(index+1,candidates,ans,temp,target);
        if(target>=candidates[index]){
            temp.push_back(candidates[index]);
            helper(index,candidates,ans,temp,target-candidates[index]);
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        helper(0,candidates,ans,{},target);
        vector<vector<int>> v;
        for(auto &i:ans){
            v.push_back(i);
        }
        return v;
    }
};