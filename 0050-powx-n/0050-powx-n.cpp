class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if (n == 1)
            return x;
            if(n%2==0)return myPow(x*x,n/2);
            else{
        if (n>0) {
            return x*myPow(x, n-1);
        } else {
            return myPow(x, n + 1) / x;
        }
            }
    }
};