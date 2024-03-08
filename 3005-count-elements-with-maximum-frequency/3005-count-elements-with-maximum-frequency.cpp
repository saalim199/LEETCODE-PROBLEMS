class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int max=0;
        int ans=0;
        for(auto it:mp){
            if(it.second==max){
                ans+=it.second;
            }else if(it.second>max){
                max=it.second;
                ans=max;
            }
        }
        return ans;
    }
};