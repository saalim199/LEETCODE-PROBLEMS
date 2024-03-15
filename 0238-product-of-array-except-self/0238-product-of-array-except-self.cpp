class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int p=1;
        int f=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) f++;
            if(nums[i]!=0) p*=nums[i];
        }
        vector<int> ans(n,0);
        if(f==n) return ans;
        for(int i=0;i<n;i++){
            if(f){
                if(nums[i]!=0)
                    ans[i]=0;
                else{
                    if(f==1) ans[i]=p;
                    else ans[i]=0;
                }
            }else{
                ans[i]=(p/nums[i]);
            }
        }
        return ans;
    }
};