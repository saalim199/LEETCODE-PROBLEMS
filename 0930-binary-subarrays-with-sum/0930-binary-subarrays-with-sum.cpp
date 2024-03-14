class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0;
        vector<int> pre(nums.size()+1);
        pre[0]=0;
        for(int i=0;i<nums.size();i++){
            pre[i+1]=pre[i]+nums[i];
        }
        for(int i=0;i<nums.size()+1;i++){
            for(int j=0;j<i;j++){
                if((pre[i]-pre[j])==goal) ans++;
                else if((pre[i]-pre[j])<goal) break;
            }
        }
        return ans;
    }
};