int MOD=1e9+7;
class Solution {
public:
    long long power(long long x, long long n){
        if(n==0) return 1;
        if(n%2==0) return power(((x%MOD)*(x%MOD)%MOD),n/2);
        return ((x%MOD)*(power(x,n-1)%MOD)%MOD);
    }
    int countGoodNumbers(long long n) {
        if(n%2==0){
            return power(20,n/2);
        }else{
            long long k=n-1;
            long long res=power(20,k/2);
            res=((res%MOD)*5)%MOD;
            return res;
        }
    }
};