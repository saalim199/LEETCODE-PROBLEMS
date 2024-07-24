class Solution {
public:
    static bool sortbyCond(const pair<int, int>& a,
                const pair<int, int>& b)
    {
    if (a.first < b.first)
        return true;
    else
       return false;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            if(temp==0){
                v.push_back({mapping[0],nums[i]});
                continue;
            }
            vector<int> t;
            while(temp!=0){
                t.push_back((temp%10));
                temp/=10;
            }
            int num=0;
            for(int j=t.size()-1;j>=0;j--){
                num*=10;
                num=num+mapping[t[j]];
            }
            v.push_back({num,nums[i]});
        }
        sort(v.begin(),v.end(), sortbyCond);
        vector<int> res;
        for(auto it:v){
            res.push_back(it.second);
        }
        return res;
    }
};