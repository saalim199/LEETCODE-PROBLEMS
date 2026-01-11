class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(auto &num:nums){
            set.insert(num);
        }
        int longest=0;
        for(auto &n : set){
            if(set.find(n-1)==set.end()){
                int count=1;
                int num=n+1;
                while(set.find(num)!=set.end()){
                    count++;
                    num++;
                }
                longest=max(count,longest);
            }
        }
        return longest;
    }
};