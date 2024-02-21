class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        int shift=0;
       while(l<r){
           shift++;
           l>>=1;
           r>>=1;
           if(l==r) break;
       }
    return l<<shift;
    }
};