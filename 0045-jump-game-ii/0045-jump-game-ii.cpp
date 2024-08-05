class Solution {
public:
    int solve(vector<int>& nums, int i){
        if(i>=(nums.size()-1)) return 0;
        int cnt=0;
        int mini=1e8;
        for(int j=1;j<=nums[i];j++){
            cnt=1+solve(nums,i+j);
            mini=min(mini,cnt);
        }
        return mini;
    }
    int jump(vector<int>& nums) {
        return solve(nums,0);
    }
};