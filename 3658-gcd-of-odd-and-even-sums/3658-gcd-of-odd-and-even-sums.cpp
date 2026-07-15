class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n*n;
        int sumEven = sumOdd + n;
        int ans = gcd(sumOdd,sumEven);
        return ans;
    }
};