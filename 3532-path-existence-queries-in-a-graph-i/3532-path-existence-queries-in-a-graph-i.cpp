class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> conn(n,0);
        int connection = 0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff) connection++;
            conn[i]=connection;
        }
        vector<bool> ans;
        for(auto &q : queries){
            ans.push_back(conn[q[0]]==conn[q[1]]);
        }
        return ans;
    }
};