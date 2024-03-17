class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ne) {
        vector<vector<int>> v;
        int n=in.size();
        int i=0;
        while(i<n && ne[0]>in[i][1]){
            v.push_back(in[i]);
            i++;
        }
        while(i<n && ne[1]>=in[i][0]){
            ne={min(ne[0],in[i][0]),max(ne[1],in[i][1])};
            i++;
        }
        v.push_back(ne);
        while(i<n){
            v.push_back(in[i]);
            i++;
        }
        return v;
    }
};