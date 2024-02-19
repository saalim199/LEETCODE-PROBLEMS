class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=1,h=nums.size()-2,mid;
        if(nums.size()==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[nums.size()-1]>nums[nums.size()-2]) return nums.size()-1;
        
        while(l<=h){
            mid=(l+h)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            if(nums[mid-1]<nums[mid]) l=mid+1;
            else h=mid-1;
        }
        return -1;
    }
};