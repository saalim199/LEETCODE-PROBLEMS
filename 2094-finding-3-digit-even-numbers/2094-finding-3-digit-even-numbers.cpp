class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<digits.size();i++){
            mp[digits[i]]++;
        }
        for(int i=100; i<=999; i=i+2){
            int num=i;
            unordered_map<int,int> temp;
            while(num){
                int rem=num%10;
                num/=10;
                temp[rem]++;
            }
            int flag=1;
            for(auto &it:temp){
                if(mp[it.first]<it.second){
                    flag=0;
                    break;
                }
            }
            if(flag) ans.push_back(i);
        }
        return ans;
    }
};