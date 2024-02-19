class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        long long a=ceil(log2(n));
        long long b=floor(log2(n));
        if(a==b) return true;
        else return false;
        // if( n>0 and (n&(n-1))==0) return 1;
        // else return 0;
        // return 0;
    }
};