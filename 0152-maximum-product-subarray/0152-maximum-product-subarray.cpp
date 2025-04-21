class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prodMax=nums[0];
        int prodMin=nums[0];
        int result=nums[0];
        for(int i=1;i<nums.size();i++){
            prodMax=max({nums[i],prodMin*nums[i],prodMax*nums[i]});
            prodMin=min({nums[i],prodMin*nums[i],prodMax*nums[i]});
            result=max(result,prodMax);
        }
        return result;
    }
};