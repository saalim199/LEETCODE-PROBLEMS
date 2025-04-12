class Solution {
public:
    long long fact(int n){
        long long res=1;
        for(int i=2;i<=n;i++){
            res*=i;
        }
        return res;
    }
    int vecTonum(vector<int> v){
        int num=0;
        for(auto d:v){
            num=(num*10)+d;
        }
        return num;
    }
    long long totalPer(int n, map<int,int> mp){
        long long total=fact(n);
        for(auto it:mp){
            total/=fact(it.second);
        }
        return total;
    }
    long long zeroPer(int n, map<int,int> mp){
        if(!mp[0]) return 0;
        long long total=fact(n-1);
        mp[0]--;
        for(auto it: mp){
            total/=fact(it.second);
        }
        return total;
    }
    void genPal(int left, int right, int div, set<map<int,int>> &st, long long &res, vector<int> num){
        if(left>right){
            //BASE
            if(vecTonum(num)%div==0){
                map<int,int> freqDigits;
                for(auto d:num){
                    freqDigits[d]++;
                }
                if(st.find(freqDigits)==st.end()){
                    res+=totalPer(num.size(),freqDigits)-zeroPer(num.size(),freqDigits);
                    st.insert(freqDigits);
                }
            }
            return;
        }
        for(int i = (left==0 ? 1 : 0); i<=9; i++){
            num[left]=num[right]=i;
            genPal(left+1,right-1,div,st,res,num);
        }
    }
    long long countGoodIntegers(int n, int k) {
        vector<int> num(n);
        long long res=0;
        set<map<int,int>> st;
        genPal(0,n-1,k,st,res,num);
        return res;
    }
};