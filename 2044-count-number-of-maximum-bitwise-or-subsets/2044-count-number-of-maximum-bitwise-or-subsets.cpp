class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int>& sub, int& res, int& maxi){
        if(i>=nums.size()){
            int sum=0;
            for(auto &s:sub){
                sum|=s;
            }
            if(sum==maxi) res++;
            return;
        }
        solve(i+1,nums,sub,res,maxi);
        sub.push_back(nums[i]);
        solve(i+1,nums,sub,res,maxi);
        sub.pop_back();
    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> sub;
        int maxi=0;
        for(auto &n:nums){
            maxi|=n;
        }
        int res=0;
        solve(0,nums,sub,res,maxi);
        return res;
    }
};