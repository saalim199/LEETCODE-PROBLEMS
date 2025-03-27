class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int ele=nums[0];
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt<0){
                cnt=1;
                ele=nums[i];
            }else if(ele==nums[i]){
                cnt++;
            }else{
                cnt--;
            }
        }
        cnt=0;
        vector<int> preSum(n);
        for(int i=0;i<n;i++){
            if(ele==nums[i]){
                cnt++;
                preSum[i]=cnt;
            }
        }
        for(int i=0;i<n-1;i++){
            int targetLeft=(i+1)/2;
            int targetRight=(n-i-1)/2;
            if(preSum[i]>targetLeft && (cnt-preSum[i])>targetRight){
                return i;
            }
        }
        return -1;
    }
};