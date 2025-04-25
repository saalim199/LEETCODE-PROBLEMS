/*
[1,1,1]
*/

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long count=0;
        int c=0;
        unordered_map<int,int> mpp;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%modulo==k) c++;
            int rem=c%modulo;
            int needed=(c+modulo-k)%modulo;
            count+=mpp[needed];
            mpp[rem]++;
        }
        return count;
    }
};