class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0);
        while(l<=h){
            int mid=(l+h)/2;
            long long sum=0;
            int cnt=1;
            for(int i=0;i<nums.size();i++){
                if(sum+nums[i]>mid){
                    cnt++;
                    sum=nums[i];
                }else{
                    sum+=nums[i];
                }
            }
            if(cnt>k){
                l=mid+1;
            }else h=mid-1;
        }
        return l;
    }
};