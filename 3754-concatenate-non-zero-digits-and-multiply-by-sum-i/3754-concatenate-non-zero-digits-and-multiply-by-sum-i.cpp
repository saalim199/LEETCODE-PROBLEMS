class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        string s = "";
        int sum = 0;
        while(n!=0){
            int digit = n%10;
            n/=10;
            sum+=digit;
            if(digit!=0) s+=(digit+'0');
        }
        reverse(s.begin(),s.end());
        long long num = stol(s);
        return sum*num;
    }
};