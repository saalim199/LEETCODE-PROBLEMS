class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        sort(m.begin(),m.end());
        int ans=0;
        vector<int> v(2);
        v[0]=m[0][0];
        v[1]=m[0][1];
        ans+=v[0]-1;
        for(int i=1;i<m.size();i++){
            if(v[1]>=m[i][0]){
                if(v[1]<m[i][1]){
                    v[1]=m[i][1];
                }
            }else{
                ans+=(m[i][0]-v[1]-1);
                v[0]=m[i][0];
                v[1]=m[i][1];
            }
        }
        ans+=days-v[1];
        return ans;
    }
};