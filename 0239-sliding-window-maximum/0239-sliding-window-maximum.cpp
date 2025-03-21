class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<pair<int,int>> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            while(!q.empty() && nums[i]>=q.back().first){
                q.pop_back();
            }
            q.push_back({nums[i],i});
            while(q.front().second<=(i-k)){
                q.pop_front();
            }
            if(i>=k-1) ans.push_back(q.front().first);
        }
        return ans;
    }
};