class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        int sum;
        while(1){
            sum=0;
            while(n){
                int digit=n%10;
                sum+=digit*digit;
                n/=10;
            }
            if(sum==1) return true;
            if(st.find(sum)!=st.end()) return false;
            st.insert(sum);
            n=sum;
        }
    }
};