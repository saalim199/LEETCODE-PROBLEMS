class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            if(nums[i]<k) return -1;
            if(nums[i]>k) cnt++;
        }
        return cnt;
    }
};