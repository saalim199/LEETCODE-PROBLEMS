class Solution {
public:
    int numTeams(vector<int>& r) {
        int n=r.size();
        vector<int> asc(n,0);
        vector<int> des(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(r[j]<r[i]){
                    asc[i]++;
                    cnt+=asc[j];
                }else{
                    des[i]++;
                    cnt+=des[j];
                }
            }
        }
        return cnt;
    }
};