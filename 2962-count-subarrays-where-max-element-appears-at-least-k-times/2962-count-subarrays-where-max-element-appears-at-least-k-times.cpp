class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int target=*max_element(nums.begin(),nums.end());
        int left=0;
        int targetCount=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(target==nums[i]) targetCount++;
            if(targetCount==k){
                while(targetCount==k && left<nums.size()){
                    if(nums[left]==target) targetCount--;
                    left++;
                }
            }
                ans+=left;
        }
        return ans;
    }
};