class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority=nums[0];
        int cnt=1;
        for(int i=1;i<nums.size();i++){
            if(majority==nums[i]) cnt++;
            else cnt--;
            if(cnt==0){ 
                majority=nums[i];
                cnt++;
            }
        }
        return majority;
    }
};