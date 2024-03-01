class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(i==nums.size()-1){ ans.push_back(nums[i]); break;}
            if(nums[i]==nums[i+1]){
                i++;
            }else{
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};