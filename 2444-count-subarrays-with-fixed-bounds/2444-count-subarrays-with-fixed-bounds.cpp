class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // deque<int> dqMin;
        // deque<int> dqMax;
        long long cnt=0;
        int left=0;
        pair<int,int> maxi={INT_MIN,-1};
        pair<int,int> mini={INT_MAX,-1};
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK){
                // dqMin.clear();
                // dqMax.clear();
                maxi.first=INT_MIN;
                maxi.second=-1;
                mini.first=INT_MAX;
                mini.second=-1;
                left=i+1;
                continue;
            }
            if(maxi.first<=nums[i]){
                maxi.first=nums[i];
                maxi.second=i;
            }
            if(mini.first>=nums[i]){
                mini.first=nums[i];
                mini.second=i;
            }
            if(maxi.first==maxK && mini.first==minK){
                cnt+=min(maxi.second,mini.second)-left+1;
            }
        }
        return cnt;
    }
};