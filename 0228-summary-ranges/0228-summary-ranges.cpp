class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return {};
        int start=nums[0];
        vector<string> res;
        for(int i=1;i<=nums.size();i++){
            if(i<nums.size() && nums[i]==nums[i-1]+1){
                continue;
            }
            if(start==nums[i-1]){
                res.push_back(to_string(start));
            }
            else{
                    string s=to_string(start);
                    s+="->";
                    s+=to_string(nums[i-1]);
                    res.push_back(s);
            }
            if(i<nums.size()){
                start=nums[i];
            }
        }
        return res;
    }
};