class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> st;
        for(auto &n:nums){
            st.insert(n);
        }
        int totalDistinct=st.size();
        int right=0;
        int ans=0;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
            while(right<=i && mp.size()==totalDistinct){
                ans+=nums.size()-i;
                mp[nums[right]]--;
                if(mp[nums[right]]==0) mp.erase(nums[right]);
                right++;
            }
        }
        return ans;
    }
};