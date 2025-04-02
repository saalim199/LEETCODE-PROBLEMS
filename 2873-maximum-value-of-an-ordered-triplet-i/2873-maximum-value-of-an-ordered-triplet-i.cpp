class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxE=INT_MIN;
        long long maxD=INT_MIN;
        long long maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            long long triplet=maxD*nums[i];
            maxD=max(maxD,maxE-nums[i]);
            maxE=max(maxE,(long long)nums[i]);
            maxi=max(triplet,maxi);
        }
        if(maxi>0) return maxi;
        return 0;
    }
};