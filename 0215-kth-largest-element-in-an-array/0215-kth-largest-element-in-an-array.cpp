class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(int &i : nums){
            q.push(i);
        }
        int ans;
        while(k--){
            ans=q.top();
            q.pop();
        }
        return ans;
    }
};