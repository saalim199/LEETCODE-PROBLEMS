class Solution {
public:
    void solve(int i,int t,vector<int>& cand,vector<vector<int>> &ans,vector<int> temp){
        if(t==0){
            ans.push_back(temp);
            return;
        }
        if(i==0){
            if(t%cand[i]==0){
                temp.insert(temp.end(),t/cand[i],cand[i]);
                ans.push_back(temp);
            }
            return;
        }//base cases
        solve(i-1,t,cand,ans,temp);
        if(cand[i]<=t){temp.push_back(cand[i]); solve(i,t-cand[i],cand,ans,temp);}
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates.size()-1,target,candidates,ans,temp);
        return ans;
    }
};