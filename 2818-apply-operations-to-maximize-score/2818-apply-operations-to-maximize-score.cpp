int MOD=1e9+7;
class Solution {
public:
    vector<int> next(vector<int> &prime){
        stack<int> st;
        vector<int> res(prime.size(),0);
        st.push(0);
        for(int i=1;i<prime.size();i++){
            while(!st.empty() && prime[st.top()]<prime[i]){
                res[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            res[st.top()]=prime.size();
            st.pop();
        }
        return res;
    }
    vector<int> prev(vector<int> &prime){
        stack<int> st;
        vector<int> res(prime.size(),0);
        st.push(prime.size()-1);
        for(int i=prime.size()-2;i>=0;i--){
            while(!st.empty() && prime[st.top()]<=prime[i]){
                res[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            res[st.top()]=-1;
            st.pop();
        }
        return res;
    }
    long long modPow(long long x, int exp) {
        if (x == 0) return 0;
        if (exp == 0) return 1;
        long long a = (exp % 2 == 1) ? x : 1;
        return modPow(x * x % MOD, exp / 2) * a % MOD;
    }
    int maximumScore(vector<int>& nums, int k) {
        long long ans=1;
        vector<int> prime;
        for(auto n:nums){
            int cnt=0;
            if(n%2==0){
                cnt++;
                while(n%2==0){
                    n/=2;
                }
            }

            for(int i=3;(i*i)<=n;i=i+2){
                if(n%i==0){
                    cnt++;
                    while(n%i==0){
                        n/=i;
                    }
                }
            }
            if(n>2) cnt++;
            prime.push_back(cnt);
        }
        // for(auto i:prime) cout<<i<<" ";
        cout<<endl;
        vector<int> left = prev(prime);
        vector<int> right = next(prime);
        vector<pair<pair<int,int>,pair<int,int>>> sorted_v;
        for(int i=0;i<nums.size();i++){
            sorted_v.push_back({{nums[i],i},{left[i],right[i]}});
        }
        sort(sorted_v.begin(),sorted_v.end());
        for(int i=sorted_v.size()-1;i>=0;i--){
            auto [n,j]=sorted_v[i].first;
            auto [l,r]=sorted_v[i].second;
            // cout<<l<<" "<<r<<endl;
            // cout<<"n="<<n<<" range="<<range<<endl;
            int mini=min((long long)(j-l)*(r-j),(long long)k);
            ans=(ans*modPow(n,mini)%MOD);
            k-=mini;
            if(k<=0) break;
        }
        return ans;
    }
};