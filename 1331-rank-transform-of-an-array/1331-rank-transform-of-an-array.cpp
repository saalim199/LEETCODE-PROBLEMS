class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]].push_back(i); 
        }
        int last= INT_MIN;
        int rank = 0;
        vector<int> ans(arr.size());
        for(auto &it : m){
            if(it.first>last){
                rank++;
                last=it.first;
            }
            for(auto &e : it.second) ans[e]=rank;
        }
        return ans;
    }
};