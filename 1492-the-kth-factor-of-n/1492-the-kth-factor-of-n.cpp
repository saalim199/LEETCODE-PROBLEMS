class Solution {
public:
    int kthFactor(int n, int k) {
        int factor=1;
        int cnt=1;
        for(int i=2;i<=n && cnt<k;i++){
            if(n%i==0){
                factor=i;
                cnt++;
            }
        }
        if(cnt==k) return factor;
        else return -1;
    }
};