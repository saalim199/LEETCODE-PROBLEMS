class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            int num=i;
            int digits=log10(num)+1;
            if(digits&1) continue;
            int half=digits/2;
            int firstHalf=0;
            int secondHalf=0;
            int j=half;
            while(j){
                secondHalf+=(num%10);
                num/=10;
                j--;
            }
            j=half;
            while(j){
                firstHalf+=(num%10);
                num/=10;
                j--;
            }
            if(firstHalf==secondHalf) cnt++;
        }
        return cnt;
    }
};