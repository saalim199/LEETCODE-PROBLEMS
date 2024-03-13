class Solution {
public:
    int pivotInteger(int n) {
        int f=1,b=(n*(n+1))/2,i=2,j=1;
        if(f==b) return b;
        while(i<=n && j<=n){
            f+=i;
            b-=j;
            if(f==b) {return i;}
            i++;
            j++;
        }
        return -1;
    }
};