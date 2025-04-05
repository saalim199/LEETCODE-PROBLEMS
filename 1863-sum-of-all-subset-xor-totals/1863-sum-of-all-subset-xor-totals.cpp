class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int> t, int &total){
        if(i>=nums.size()){
            int temp=0;
            for(auto a:t){
                temp^=a;
            }
            total+=temp;
            return;
        }
        solve(i+1,nums,t,total);
        t.push_back(nums[i]);
        solve(i+1,nums,t,total);
    }
    int subsetXORSum(vector<int>& nums) {
        int total=0;
        solve(0,nums,{},total);
        return total;
    }
};