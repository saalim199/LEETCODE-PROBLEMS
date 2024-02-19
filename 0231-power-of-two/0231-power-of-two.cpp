class Solution {
public:
    bool isPowerOfTwo(int n) {
        // float a=log2(n);
        // int b=floor(a);
        // if(a==b) return true;
        // else return false;
        if( n>0 and (n&(n-1))==0) return 1;
        else return 0;
        return 0;
    }
};