class Solution {
public:
    int mySqrt(int x) {
        int l=0,h=x;
        while(l<=h){
            int m=(l+h)/2;
            long long int n=m*1LL*m;
            if(n<=(long)x) l=m+1;
            else h=m-1;
        }
        return l-1;
    }
};