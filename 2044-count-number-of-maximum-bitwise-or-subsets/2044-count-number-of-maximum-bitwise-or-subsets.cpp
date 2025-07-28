class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int>& sub, unordered_map<int,int>& orMap){
        if(i>=nums.size()){
            int sum=0;
            for(auto &s:sub){
                sum|=s;
            }
            orMap[sum]++;
            return;
        }
        solve(i+1,nums,sub,orMap);
        sub.push_back(nums[i]);
        solve(i+1,nums,sub,orMap);
        sub.pop_back();
    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> sub;
        unordered_map<int,int> orMap;
        int maxi=0;
        int res=0;
        solve(0,nums,sub,orMap);
        for(auto &[x,y]:orMap){
            // cout<<x<<" "<<y<<endl;
            if(x>maxi){
                maxi=x;
                res=y;
            }
        }
        return res;
    }
};