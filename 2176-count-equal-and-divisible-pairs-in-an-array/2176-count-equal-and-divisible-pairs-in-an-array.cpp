class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    if((i*j)%k==0) total++;
                }
            }
        }
        return total;
    }
};